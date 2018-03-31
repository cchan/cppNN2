#include <string>

#undef assert

inline void assert(bool x, std::string msg){
  if(!x)
    throw std::invalid_argument(msg);
}
const std::string ERR_SIZE_MISMATCH = "vec size mismatch";
