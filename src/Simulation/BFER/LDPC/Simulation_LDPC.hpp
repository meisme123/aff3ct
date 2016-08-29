#ifndef SIMULATION_LDPC_HPP_
#define SIMULATION_LDPC_HPP_

#include "../Simulation_BFER.hpp"

template <typename B, typename R, typename Q>
class Simulation_LDPC : public Simulation_BFER<B,R,Q>
{
protected:
	// LDPC bi-partite graph representation
	std::vector<unsigned char> n_variables_per_parity;
	std::vector<unsigned char> n_parities_per_variable;
	std::vector<unsigned int > transpose;

public:
	Simulation_LDPC(const t_simulation_param& simu_params,
	                const t_code_param&       code_params,
	                const t_encoder_param&    enco_params,
	                const t_mod_param&        mod_params,
	                const t_channel_param&    chan_params,
	                const t_decoder_param&    deco_params);

	virtual ~Simulation_LDPC();

protected:
	void          launch_precompute();
	void          snr_precompute   ();
	Encoder<B>*   build_encoder    (const int tid = 0);
	Decoder<B,Q>* build_decoder    (const int tid = 0);
};

#endif /* SIMULATION_LDPC_HPP_ */