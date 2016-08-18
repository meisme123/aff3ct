#ifndef DECODER_LDPC_BP_SUM_PRODUCT_NAIVE_HPP_
#define DECODER_LDPC_BP_SUM_PRODUCT_NAIVE_HPP_

#include "Decoder_LDPC_BP_naive.hpp"

template <typename B, typename R>
class Decoder_LDPC_BP_sum_product_naive : public Decoder_LDPC_BP_naive<B,R>
{
public:
	Decoder_LDPC_BP_sum_product_naive(const int &N, const int &K, const int& n_ite, 
	                                  const std::vector<unsigned char> &n_variables_per_parity,
	                                  const std::vector<unsigned char> &n_parities_per_variable,
	                                  const std::vector<unsigned int > &transpose);
	virtual ~Decoder_LDPC_BP_sum_product_naive();

protected:
	// BP functions for decoding
	virtual bool BP_process();
};

#endif /* DECODER_LDPC_BP_SUM_PRODUCT_NAIVE_HPP_ */