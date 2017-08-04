#ifndef DECODER_POLAR_SCAN_NAIVE_SYS_
#define DECODER_POLAR_SCAN_NAIVE_SYS_

#include <vector>
#include <mipp.h>

#include "Tools/Code/Polar/decoder_polar_functions.h"

#include "Decoder_polar_SCAN_naive.hpp"

namespace aff3ct
{
namespace module
{
template <typename B = int, typename R = float, tools::proto_i<  R> I = tools::init_LLR,
                                                tools::proto_f<  R> F = tools::f_LLR,
                                                tools::proto_v<  R> V = tools::v_LLR,
                                                tools::proto_h<B,R> H = tools::h_LLR,
                                                tools::proto_s<  R> S = tools::sat_val>
class Decoder_polar_SCAN_naive_sys : public Decoder_polar_SCAN_naive<B,R,I,F,V,H>
{
public:
	Decoder_polar_SCAN_naive_sys(const int &K, const int &N, const int &max_iter, const std::vector<bool> &frozen_bits,
	                             const int n_frames = 1, const std::string name = "Decoder_polar_SCAN_naive_sys");
	virtual ~Decoder_polar_SCAN_naive_sys();

protected:
	void _decode_siso(const R *sys, const R *par, R *ext, const int frame_id);
	void _decode_siso(const R *Y_N1, R *Y_N2, const int frame_id);
	void _store(B *V_KN, bool coded = false) const;
};
}
}

#include "Decoder_polar_SCAN_naive_sys.hxx"

#endif /* DECODER_POLAR_SCAN_NAIVE_SYS_ */
