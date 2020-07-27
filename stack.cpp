
#include "stack.h"

stack:: stack( ):
  current_size(0),
  current_capacity(10),
  data(new double[10])
{
}


stack:: stack( const stack& s ):
  current_size(s.current_size),
  current_capacity(s.current_capacity),
  data(new double[s.current_capacity])
{
  for(size_t i=0; i<s.current_size; ++i) {
    data[i]=s.data[i];
  }
}

stack::~stack( ){
  delete[] data;
}

void stack::ensure_capacity( size_t c )
{
  if( current_capacity < c )
  {

     if( c < 2 * current_capacity )
        c = 2 * current_capacity;

     double* newdata = new double[ c ];
     for( size_t i = 0; i < current_size; ++ i )
        newdata[i] = data[i];

     current_capacity = c;
     delete[] data;
     data = newdata;
  }
}


const stack& stack::operator = ( const stack& s )
{
  current_size=s.current_size;
  ensure_capacity(s.current_size);
  for(size_t i=0; i<s.current_size; i++){
    data[i]=s.data[i];
  }
  return *this;
}



stack::stack( std::initializer_list<double> init ):
  current_size(init.size()),
  current_capacity(init.size()),
  data(new double[init.size()])

{
  size_t i=0;
  for(double d:init) {
    data[i]=d;
    ++i;
   }
}

void stack::push( double d )
{
  ensure_capacity(current_size+1);
  data[current_size]=d;
  ++current_size;

}

void stack::pop( )
{
  current_size--;

}

void stack::clear( ){
  current_size=0;
}

void stack::reset( size_t s ){
  current_size=s;
}

double stack::peek( ) const{
  return data[current_size-1];
}

size_t stack::size( ) const {
  return current_size;
}

bool stack::empty( ) const{
  if(current_size==0){
    return true;
  }else {
    return false;
  }

}

std::ostream& operator << ( std::ostream& out, const stack& s) {
  out << "{";
  for(size_t i=0; i<s.current_size; ++i){
    out << s.data[i];
    if (i!=s.current_size-1){
      out << " ";
    }
  }
  out << "}" << std::endl;
  return out;
}
