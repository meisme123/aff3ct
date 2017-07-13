#ifndef FACTORY_ENCODER_RA_HPP
#define FACTORY_ENCODER_RA_HPP

#include <string>

#include "Module/Encoder/Encoder.hpp"
#include "Module/Interleaver/Interleaver.hpp"

#include "../Factory_encoder.hpp"

namespace aff3ct
{
namespace tools
{
struct Factory_encoder_RA : public Factory_encoder
{
	template <typename B = int>
	static module::Encoder<B>* build(const Factory_encoder::parameters& params,
	                                 const module::Interleaver<int> &itl);

	static void build_args(Arguments_reader::arg_map &req_args, Arguments_reader::arg_map &opt_args);
	static void store_args(const Arguments_reader& ar, Factory_encoder::parameters &params,
	                       int K, int N, int n_frames = 1);
	static void group_args(Arguments_reader::arg_grp& ar);

	static void header(params_list& head_enc, params_list& head_cde, const Factory_encoder::parameters& params);
};
}
}

#endif /* FACTORY_ENCODER_RA_HPP */