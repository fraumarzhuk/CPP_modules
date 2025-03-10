#ifndef ITER_HPP
#define ITER_HPP


template <typename I, typename F>

void iter(I *adr, size_t len, const F function) {
	if (!function || len == 0 || adr == NULL)
		return ;
	for (size_t i = 0; i < len; ++i) {
		function(adr[i]);
	}
}

#endif