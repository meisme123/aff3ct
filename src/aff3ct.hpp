#ifndef AFF3CT_HPP
#define AFF3CT_HPP

#include <Tools/Code/Polar/API/functions_polar_inter.h>
#include <Tools/Code/Polar/API/functions_polar_inter_8bit_bitpacking.h>
#include <Tools/Code/Polar/API/functions_polar_inter_intra.h>
#include <Tools/Code/Polar/API/functions_polar_intra.h>
#include <Tools/Code/Polar/API/functions_polar_intra_16bit.h>
#include <Tools/Code/Polar/API/functions_polar_intra_32bit.h>
#include <Tools/Code/Polar/API/functions_polar_intra_8bit.h>
#include <Tools/Code/Polar/API/functions_polar_seq.h>
#include <Tools/Code/Polar/decoder_polar_functions.h>
#include <Tools/Code/Polar/fb_extract.h>
#include <Tools/Code/Polar/nodes_parser.h>
#include <Tools/Display/rang_format/rang_format.h>
#include <Tools/general_utils.h>
#include <Tools/Math/interpolation.h>
#include <Tools/Math/matrix.h>
#include <Tools/Math/max.h>
#include <Tools/Math/numerical_integration.h>
#include <Tools/Math/utils.h>
#include <Tools/Noise/noise_utils.h>
#include <Tools/Perf/common/hard_decide.h>
#include <Tools/Perf/common/mutual_info.h>
#include <Tools/Perf/compute_parity.h>
#include <Tools/Perf/distance/Bitwise_diff.h>
#include <Tools/Perf/distance/Boolean_diff.h>
#include <Tools/Perf/distance/distance.h>
#include <Tools/Perf/distance/hamming_distance.h>
#include <Tools/Perf/Transpose/transpose_AVX.h>
#include <Tools/Perf/Transpose/transpose_NEON.h>
#include <Tools/Perf/Transpose/transpose_selector.h>
#include <Tools/Perf/Transpose/transpose_SSE.h>
#include <Tools/system_functions.h>
#include <Tools/types.h>
#include <Tools/version.h>

#include <Factory/Command_parser.hpp>
#include <Factory/Factory.hpp>
#include <Factory/Launcher/Launcher.hpp>
#include <Factory/Module/Channel/Channel.hpp>
#include <Factory/Module/Codec/BCH/Codec_BCH.hpp>
#include <Factory/Module/Codec/Codec.hpp>
#include <Factory/Module/Codec/Codec_HIHO.hpp>
#include <Factory/Module/Codec/Codec_SIHO.hpp>
#include <Factory/Module/Codec/Codec_SIHO_HIHO.hpp>
#include <Factory/Module/Codec/Codec_SISO.hpp>
#include <Factory/Module/Codec/Codec_SISO_SIHO.hpp>
#include <Factory/Module/Codec/LDPC/Codec_LDPC.hpp>
#include <Factory/Module/Codec/Polar/Codec_polar.hpp>
#include <Factory/Module/Codec/RA/Codec_RA.hpp>
#include <Factory/Module/Codec/Repetition/Codec_repetition.hpp>
#include <Factory/Module/Codec/RS/Codec_RS.hpp>
#include <Factory/Module/Codec/RSC/Codec_RSC.hpp>
#include <Factory/Module/Codec/RSC_DB/Codec_RSC_DB.hpp>
#include <Factory/Module/Codec/Turbo/Codec_turbo.hpp>
#include <Factory/Module/Codec/Turbo_DB/Codec_turbo_DB.hpp>
#include <Factory/Module/Codec/Turbo_product/Codec_turbo_product.hpp>
#include <Factory/Module/Codec/Uncoded/Codec_uncoded.hpp>
#include <Factory/Module/Coset/Coset.hpp>
#include <Factory/Module/CRC/CRC.hpp>
#include <Factory/Module/Decoder/BCH/Decoder_BCH.hpp>
#include <Factory/Module/Decoder/Decoder.hpp>
#include <Factory/Module/Decoder/LDPC/Decoder_LDPC.hpp>
#include <Factory/Module/Decoder/NO/Decoder_NO.hpp>
#include <Factory/Module/Decoder/Polar/Decoder_polar.hpp>
#include <Factory/Module/Decoder/RA/Decoder_RA.hpp>
#include <Factory/Module/Decoder/Repetition/Decoder_repetition.hpp>
#include <Factory/Module/Decoder/RS/Decoder_RS.hpp>
#include <Factory/Module/Decoder/RSC/Decoder_RSC.hpp>
#include <Factory/Module/Decoder/RSC_DB/Decoder_RSC_DB.hpp>
#include <Factory/Module/Decoder/Turbo/Decoder_turbo.hpp>
#include <Factory/Module/Decoder/Turbo_DB/Decoder_turbo_DB.hpp>
#include <Factory/Module/Decoder/Turbo_product/Decoder_turbo_product.hpp>
#include <Factory/Module/Encoder/BCH/Encoder_BCH.hpp>
#include <Factory/Module/Encoder/Encoder.hpp>
#include <Factory/Module/Encoder/LDPC/Encoder_LDPC.hpp>
#include <Factory/Module/Encoder/Polar/Encoder_polar.hpp>
#include <Factory/Module/Encoder/RA/Encoder_RA.hpp>
#include <Factory/Module/Encoder/Repetition/Encoder_repetition.hpp>
#include <Factory/Module/Encoder/RS/Encoder_RS.hpp>
#include <Factory/Module/Encoder/RSC/Encoder_RSC.hpp>
#include <Factory/Module/Encoder/RSC_DB/Encoder_RSC_DB.hpp>
#include <Factory/Module/Encoder/Turbo/Encoder_turbo.hpp>
#include <Factory/Module/Encoder/Turbo_DB/Encoder_turbo_DB.hpp>
#include <Factory/Module/Encoder/Turbo_product/Encoder_turbo_product.hpp>
#include <Factory/Module/Interleaver/Interleaver.hpp>
#include <Factory/Module/Modem/Modem.hpp>
#include <Factory/Module/Monitor/BFER/Monitor_BFER.hpp>
#include <Factory/Module/Monitor/EXIT/Monitor_EXIT.hpp>
#include <Factory/Module/Monitor/MI/Monitor_MI.hpp>
#include <Factory/Module/Monitor/Monitor.hpp>
#include <Factory/Module/Puncturer/LDPC/Puncturer_LDPC.hpp>
#include <Factory/Module/Puncturer/Polar/Puncturer_polar.hpp>
#include <Factory/Module/Puncturer/Puncturer.hpp>
#include <Factory/Module/Puncturer/Turbo/Puncturer_turbo.hpp>
#include <Factory/Module/Puncturer/Turbo_DB/Puncturer_turbo_DB.hpp>
#include <Factory/Module/Quantizer/Quantizer.hpp>
#include <Factory/Module/Source/Source.hpp>
#include <Factory/Simulation/BFER/BFER.hpp>
#include <Factory/Simulation/BFER/BFER_ite.hpp>
#include <Factory/Simulation/BFER/BFER_std.hpp>
#include <Factory/Simulation/EXIT/EXIT.hpp>
#include <Factory/Simulation/Simulation.hpp>
#include <Factory/Tools/Code/Polar/Frozenbits_generator.hpp>
#include <Factory/Tools/Code/Turbo/Flip_and_check.hpp>
#include <Factory/Tools/Code/Turbo/Flip_and_check_DB.hpp>
#include <Factory/Tools/Code/Turbo/Scaling_factor.hpp>
#include <Factory/Tools/Display/Terminal/Terminal.hpp>
#include <Factory/Tools/Interleaver/Interleaver_core.hpp>
#include <Factory/Tools/Noise/Noise.hpp>
#include <Launcher/Code/BCH/BCH.hpp>
#include <Launcher/Code/LDPC/LDPC.hpp>
#include <Launcher/Code/Polar/Polar.hpp>
#include <Launcher/Code/RA/RA.hpp>
#include <Launcher/Code/Repetition/Repetition.hpp>
#include <Launcher/Code/RS/RS.hpp>
#include <Launcher/Code/RSC/RSC.hpp>
#include <Launcher/Code/RSC_DB/RSC_DB.hpp>
#include <Launcher/Code/Turbo/Turbo.hpp>
#include <Launcher/Code/Turbo_DB/Turbo_DB.hpp>
#include <Launcher/Code/Turbo_product/Turbo_product.hpp>
#include <Launcher/Code/Uncoded/Uncoded.hpp>
#include <Launcher/Launcher.hpp>
#include <Launcher/Simulation/BFER_ite.hpp>
#include <Launcher/Simulation/BFER_std.hpp>
#include <Launcher/Simulation/EXIT.hpp>
#include <Module/Channel/AWGN/Channel_AWGN_LLR.hpp>
#include <Module/Channel/Binary_erasure/Channel_binary_erasure.hpp>
#include <Module/Channel/Binary_symmetric/Channel_binary_symmetric.hpp>
#include <Module/Channel/Channel.hpp>
#include <Module/Channel/NO/Channel_NO.hpp>
#include <Module/Channel/Optical/Channel_optical.hpp>
#include <Module/Channel/Rayleigh/Channel_Rayleigh_LLR.hpp>
#include <Module/Channel/Rayleigh/Channel_Rayleigh_LLR_user.hpp>
#include <Module/Channel/User/Channel_user.hpp>
#include <Module/Codec/BCH/Codec_BCH.hpp>
#include <Module/Codec/Codec.hpp>
#include <Module/Codec/Codec_HIHO.hpp>
#include <Module/Codec/Codec_SIHO.hpp>
#include <Module/Codec/Codec_SIHO_HIHO.hpp>
#include <Module/Codec/Codec_SISO.hpp>
#include <Module/Codec/Codec_SISO_SIHO.hpp>
#include <Module/Codec/LDPC/Codec_LDPC.hpp>
#include <Module/Codec/Polar/Codec_polar.hpp>
#include <Module/Codec/RA/Codec_RA.hpp>
#include <Module/Codec/Repetition/Codec_repetition.hpp>
#include <Module/Codec/RS/Codec_RS.hpp>
#include <Module/Codec/RSC/Codec_RSC.hpp>
#include <Module/Codec/RSC_DB/Codec_RSC_DB.hpp>
#include <Module/Codec/Turbo/Codec_turbo.hpp>
#include <Module/Codec/Turbo_DB/Codec_turbo_DB.hpp>
#include <Module/Codec/Turbo_product/Codec_turbo_product.hpp>
#include <Module/Codec/Uncoded/Codec_uncoded.hpp>
#include <Module/Coset/Bit/Coset_bit.hpp>
#include <Module/Coset/Coset.hpp>
#include <Module/Coset/Real/Coset_real.hpp>
#include <Module/CRC/CRC.hpp>
#include <Module/CRC/NO/CRC_NO.hpp>
#include <Module/CRC/Polynomial/CRC_polynomial.hpp>
#include <Module/CRC/Polynomial/CRC_polynomial_fast.hpp>
#include <Module/CRC/Polynomial/CRC_polynomial_inter.hpp>
#include <Module/Decoder/BCH/Decoder_BCH.hpp>
#include <Module/Decoder/BCH/Fast/Decoder_BCH_fast.hpp>
#include <Module/Decoder/BCH/Genius/Decoder_BCH_genius.hpp>
#include <Module/Decoder/BCH/Standard/Decoder_BCH_std.hpp>
#include <Module/Decoder/Decoder.hpp>
#include <Module/Decoder/Decoder_HIHO.hpp>
#include <Module/Decoder/Decoder_SIHO.hpp>
#include <Module/Decoder/Decoder_SIHO_HIHO.hpp>
#include <Module/Decoder/Decoder_SISO.hpp>
#include <Module/Decoder/Decoder_SISO_SIHO.hpp>
#include <Module/Decoder/Generic/Chase/Decoder_chase_std.hpp>
#include <Module/Decoder/Generic/ML/Decoder_maximum_likelihood.hpp>
#include <Module/Decoder/Generic/ML/Decoder_maximum_likelihood_naive.hpp>
#include <Module/Decoder/Generic/ML/Decoder_maximum_likelihood_std.hpp>
#include <Module/Decoder/LDPC/BP/Decoder_LDPC_BP.hpp>
#include <Module/Decoder/LDPC/BP/Flooding/Decoder_LDPC_BP_flooding.hpp>
#include <Module/Decoder/LDPC/BP/Flooding/Decoder_LDPC_BP_flooding_inter.hpp>
#include <Module/Decoder/LDPC/BP/Flooding/Gallager/Decoder_LDPC_BP_flooding_Gallager_A.hpp>
#include <Module/Decoder/LDPC/BP/Horizontal_layered/Decoder_LDPC_BP_horizontal_layered.hpp>
#include <Module/Decoder/LDPC/BP/Horizontal_layered/Decoder_LDPC_BP_horizontal_layered_inter.hpp>
#include <Module/Decoder/LDPC/BP/Horizontal_layered/ONMS/Decoder_LDPC_BP_horizontal_layered_ONMS_inter.hpp>
#include <Module/Decoder/LDPC/BP/Peeling/Decoder_LDPC_BP_peeling.hpp>
#include <Module/Decoder/LDPC/BP/Vertical_layered/Decoder_LDPC_BP_vertical_layered.hpp>
#include <Module/Decoder/LDPC/BP/Vertical_layered/Decoder_LDPC_BP_vertical_layered_inter.hpp>
#include <Module/Decoder/NO/Decoder_NO.hpp>
#include <Module/Decoder/Polar/ASCL/Decoder_polar_ASCL_fast_CA_sys.hpp>
#include <Module/Decoder/Polar/ASCL/Decoder_polar_ASCL_MEM_fast_CA_sys.hpp>
#include <Module/Decoder/Polar/SC/Decoder_polar_SC_fast_sys.hpp>
#include <Module/Decoder/Polar/SC/Decoder_polar_SC_naive.hpp>
#include <Module/Decoder/Polar/SC/Decoder_polar_SC_naive_sys.hpp>
#include <Module/Decoder/Polar/SCAN/Decoder_polar_SCAN_naive.hpp>
#include <Module/Decoder/Polar/SCAN/Decoder_polar_SCAN_naive_sys.hpp>
#include <Module/Decoder/Polar/SCL/CRC/Decoder_polar_SCL_fast_CA_sys.hpp>
#include <Module/Decoder/Polar/SCL/CRC/Decoder_polar_SCL_MEM_fast_CA_sys.hpp>
#include <Module/Decoder/Polar/SCL/CRC/Decoder_polar_SCL_naive_CA.hpp>
#include <Module/Decoder/Polar/SCL/CRC/Decoder_polar_SCL_naive_CA_sys.hpp>
#include <Module/Decoder/Polar/SCL/Decoder_polar_SCL_fast_sys.hpp>
#include <Module/Decoder/Polar/SCL/Decoder_polar_SCL_MEM_fast_sys.hpp>
#include <Module/Decoder/Polar/SCL/Decoder_polar_SCL_naive.hpp>
#include <Module/Decoder/Polar/SCL/Decoder_polar_SCL_naive_sys.hpp>
#include <Module/Decoder/RA/Decoder_RA.hpp>
#include <Module/Decoder/Repetition/Decoder_repetition.hpp>
#include <Module/Decoder/Repetition/Decoder_repetition_fast.hpp>
#include <Module/Decoder/Repetition/Decoder_repetition_std.hpp>
#include <Module/Decoder/RS/Decoder_RS.hpp>
#include <Module/Decoder/RS/Genius/Decoder_RS_genius.hpp>
#include <Module/Decoder/RS/Standard/Decoder_RS_std.hpp>
#include <Module/Decoder/RSC/BCJR/Decoder_RSC_BCJR.hpp>
#include <Module/Decoder/RSC/BCJR/Inter/Decoder_RSC_BCJR_inter.hpp>
#include <Module/Decoder/RSC/BCJR/Inter/Decoder_RSC_BCJR_inter_fast.hpp>
#include <Module/Decoder/RSC/BCJR/Inter/Decoder_RSC_BCJR_inter_std.hpp>
#include <Module/Decoder/RSC/BCJR/Inter/Decoder_RSC_BCJR_inter_very_fast.hpp>
#include <Module/Decoder/RSC/BCJR/Inter_intra/Decoder_RSC_BCJR_inter_intra.hpp>
#include <Module/Decoder/RSC/BCJR/Inter_intra/Decoder_RSC_BCJR_inter_intra_fast_x2_AVX.hpp>
#include <Module/Decoder/RSC/BCJR/Inter_intra/Decoder_RSC_BCJR_inter_intra_fast_x2_SSE.hpp>
#include <Module/Decoder/RSC/BCJR/Inter_intra/Decoder_RSC_BCJR_inter_intra_fast_x4_AVX.hpp>
#include <Module/Decoder/RSC/BCJR/Intra/Decoder_RSC_BCJR_intra.hpp>
#include <Module/Decoder/RSC/BCJR/Intra/Decoder_RSC_BCJR_intra_fast.hpp>
#include <Module/Decoder/RSC/BCJR/Intra/Decoder_RSC_BCJR_intra_std.hpp>
#include <Module/Decoder/RSC/BCJR/Seq/Decoder_RSC_BCJR_seq.hpp>
#include <Module/Decoder/RSC/BCJR/Seq/Decoder_RSC_BCJR_seq_fast.hpp>
#include <Module/Decoder/RSC/BCJR/Seq/Decoder_RSC_BCJR_seq_scan.hpp>
#include <Module/Decoder/RSC/BCJR/Seq/Decoder_RSC_BCJR_seq_std.hpp>
#include <Module/Decoder/RSC/BCJR/Seq/Decoder_RSC_BCJR_seq_very_fast.hpp>
#include <Module/Decoder/RSC/BCJR/Seq_generic/Decoder_RSC_BCJR_seq_generic.hpp>
#include <Module/Decoder/RSC/BCJR/Seq_generic/Decoder_RSC_BCJR_seq_generic_std.hpp>
#include <Module/Decoder/RSC/BCJR/Seq_generic/Decoder_RSC_BCJR_seq_generic_std_json.hpp>
#include <Module/Decoder/RSC_DB/BCJR/Decoder_RSC_DB_BCJR.hpp>
#include <Module/Decoder/RSC_DB/BCJR/Decoder_RSC_DB_BCJR_DVB_RCS1.hpp>
#include <Module/Decoder/RSC_DB/BCJR/Decoder_RSC_DB_BCJR_DVB_RCS2.hpp>
#include <Module/Decoder/RSC_DB/BCJR/Decoder_RSC_DB_BCJR_generic.hpp>
#include <Module/Decoder/Turbo/Decoder_turbo.hpp>
#include <Module/Decoder/Turbo/Decoder_turbo_fast.hpp>
#include <Module/Decoder/Turbo/Decoder_turbo_std.hpp>
#include <Module/Decoder/Turbo_DB/Decoder_turbo_DB.hpp>
#include <Module/Decoder/Turbo_product/Chase_pyndiah/Decoder_chase_pyndiah.hpp>
#include <Module/Decoder/Turbo_product/Chase_pyndiah/Decoder_chase_pyndiah_fast.hpp>
#include <Module/Decoder/Turbo_product/Decoder_turbo_product.hpp>
#include <Module/Encoder/AZCW/Encoder_AZCW.hpp>
#include <Module/Encoder/BCH/Encoder_BCH.hpp>
#include <Module/Encoder/Coset/Encoder_coset.hpp>
#include <Module/Encoder/Encoder.hpp>
#include <Module/Encoder/LDPC/DVBS2/Encoder_LDPC_DVBS2.hpp>
#include <Module/Encoder/LDPC/Encoder_LDPC.hpp>
#include <Module/Encoder/LDPC/From_H/Encoder_LDPC_from_H.hpp>
#include <Module/Encoder/LDPC/From_IRA/Encoder_LDPC_from_IRA.hpp>
#include <Module/Encoder/LDPC/From_QC/Encoder_LDPC_from_QC.hpp>
#include <Module/Encoder/NO/Encoder_NO.hpp>
#include <Module/Encoder/Polar/Encoder_polar.hpp>
#include <Module/Encoder/Polar/Encoder_polar_sys.hpp>
#include <Module/Encoder/RA/Encoder_RA.hpp>
#include <Module/Encoder/Repetition/Encoder_repetition_sys.hpp>
#include <Module/Encoder/RS/Encoder_RS.hpp>
#include <Module/Encoder/RSC/Encoder_RSC3_CPE_sys.hpp>
#include <Module/Encoder/RSC/Encoder_RSC_generic_json_sys.hpp>
#include <Module/Encoder/RSC/Encoder_RSC_generic_sys.hpp>
#include <Module/Encoder/RSC/Encoder_RSC_sys.hpp>
#include <Module/Encoder/RSC_DB/Encoder_RSC_DB.hpp>
#include <Module/Encoder/Turbo/Encoder_turbo.hpp>
#include <Module/Encoder/Turbo/Encoder_turbo_legacy.hpp>
#include <Module/Encoder/Turbo_DB/Encoder_turbo_DB.hpp>
#include <Module/Encoder/Turbo_product/Encoder_turbo_product.hpp>
#include <Module/Encoder/User/Encoder_user.hpp>
#include <Module/Interleaver/Interleaver.hpp>
#include <Module/Modem/BPSK/Modem_BPSK.hpp>
#include <Module/Modem/BPSK/Modem_BPSK_fast.hpp>
#include <Module/Modem/CPM/BCJR/CPM_BCJR.hpp>
#include <Module/Modem/CPM/CPE/Encoder_CPE.hpp>
#include <Module/Modem/CPM/CPE/Encoder_CPE_Rimoldi.hpp>
#include <Module/Modem/CPM/CPM_parameters.hpp>
#include <Module/Modem/CPM/Modem_CPM.hpp>
#include <Module/Modem/Modem.hpp>
#include <Module/Modem/OOK/Modem_OOK.hpp>
#include <Module/Modem/OOK/Modem_OOK_AWGN.hpp>
#include <Module/Modem/OOK/Modem_OOK_BEC.hpp>
#include <Module/Modem/OOK/Modem_OOK_BSC.hpp>
#include <Module/Modem/OOK/Modem_OOK_optical.hpp>
#include <Module/Modem/PAM/Modem_PAM.hpp>
#include <Module/Modem/PSK/Modem_PSK.hpp>
#include <Module/Modem/QAM/Modem_QAM.hpp>
#include <Module/Modem/SCMA/Modem_SCMA.hpp>
#include <Module/Modem/User/Modem_user.hpp>
#include <Module/Module.hpp>
#include <Module/Monitor/BFER/Monitor_BFER.hpp>
#include <Module/Monitor/EXIT/Monitor_EXIT.hpp>
#include <Module/Monitor/MI/Monitor_MI.hpp>
#include <Module/Monitor/Monitor.hpp>
#include <Module/Monitor/Monitor_reduction.hpp>
#include <Module/Monitor/Monitor_reduction_MPI.hpp>
#include <Module/Puncturer/LDPC/Puncturer_LDPC.hpp>
#include <Module/Puncturer/NO/Puncturer_NO.hpp>
#include <Module/Puncturer/Polar/Puncturer_polar_shortlast.hpp>
#include <Module/Puncturer/Puncturer.hpp>
#include <Module/Puncturer/Turbo/Puncturer_turbo.hpp>
#include <Module/Puncturer/Turbo_DB/Puncturer_turbo_DB.hpp>
#include <Module/Quantizer/Custom/Quantizer_custom.hpp>
#include <Module/Quantizer/NO/Quantizer_NO.hpp>
#include <Module/Quantizer/Pow2/Quantizer_pow2.hpp>
#include <Module/Quantizer/Pow2/Quantizer_pow2_fast.hpp>
#include <Module/Quantizer/Quantizer.hpp>
#include <Module/SC_Module.hpp>
#include <Module/Socket.hpp>
#include <Module/Source/AZCW/Source_AZCW.hpp>
#include <Module/Source/Random/Source_random.hpp>
#include <Module/Source/Random/Source_random_fast.hpp>
#include <Module/Source/Source.hpp>
#include <Module/Source/User/Source_user.hpp>
#include <Module/Task.hpp>
#include <Simulation/BFER/BFER.hpp>
#include <Simulation/BFER/Iterative/BFER_ite.hpp>
#include <Simulation/BFER/Iterative/SystemC/SC_BFER_ite.hpp>
#include <Simulation/BFER/Iterative/Threads/BFER_ite_threads.hpp>
#include <Simulation/BFER/Standard/BFER_std.hpp>
#include <Simulation/BFER/Standard/SystemC/SC_BFER_std.hpp>
#include <Simulation/BFER/Standard/Threads/BFER_std_threads.hpp>
#include <Simulation/EXIT/EXIT.hpp>
#include <Simulation/Simulation.hpp>
#include <Tools/Algo/Bit_packer.hpp>
#include <Tools/Algo/Draw_generator/Draw_generator.hpp>
#include <Tools/Algo/Draw_generator/Event_generator/Event_generator.hpp>
#include <Tools/Algo/Draw_generator/Event_generator/Fast/Event_generator_fast.hpp>
#include <Tools/Algo/Draw_generator/Event_generator/GSL/Event_generator_GSL.hpp>
#include <Tools/Algo/Draw_generator/Event_generator/MKL/Event_generator_MKL.hpp>
#include <Tools/Algo/Draw_generator/Event_generator/Standard/Event_generator_std.hpp>
#include <Tools/Algo/Draw_generator/Gaussian_noise_generator/Fast/Gaussian_noise_generator_fast.hpp>
#include <Tools/Algo/Draw_generator/Gaussian_noise_generator/Gaussian_noise_generator.hpp>
#include <Tools/Algo/Draw_generator/Gaussian_noise_generator/GSL/Gaussian_noise_generator_GSL.hpp>
#include <Tools/Algo/Draw_generator/Gaussian_noise_generator/MKL/Gaussian_noise_generator_MKL.hpp>
#include <Tools/Algo/Draw_generator/Gaussian_noise_generator/Standard/Gaussian_noise_generator_std.hpp>
#include <Tools/Algo/Draw_generator/User_pdf_noise_generator/Fast/User_pdf_noise_generator_fast.hpp>
#include <Tools/Algo/Draw_generator/User_pdf_noise_generator/GSL/User_pdf_noise_generator_GSL.hpp>
#include <Tools/Algo/Draw_generator/User_pdf_noise_generator/MKL/User_pdf_noise_generator_MKL.hpp>
#include <Tools/Algo/Draw_generator/User_pdf_noise_generator/Standard/User_pdf_noise_generator_std.hpp>
#include <Tools/Algo/Draw_generator/User_pdf_noise_generator/User_pdf_noise_generator.hpp>
#include <Tools/Algo/Histogram.hpp>
#include <Tools/Algo/Predicate.hpp>
#include <Tools/Algo/Predicate_ite.hpp>
#include <Tools/Algo/PRNG/PRNG_MT19937.hpp>
#include <Tools/Algo/PRNG/PRNG_MT19937_simd.hpp>
#include <Tools/Algo/Sort/LC_sorter.hpp>
#include <Tools/Algo/Sort/LC_sorter_simd.hpp>
#include <Tools/Algo/Sparse_matrix/Sparse_matrix.hpp>
#include <Tools/Algo/Tree/Binary_node.hpp>
#include <Tools/Algo/Tree/Binary_tree.hpp>
#include <Tools/Algo/Tree/Binary_tree_metric.hpp>
#include <Tools/Arguments/Argument_handler.hpp>
#include <Tools/Arguments/Argument_tools.hpp>
#include <Tools/Arguments/Maps/Argument_info.hpp>
#include <Tools/Arguments/Maps/Argument_links.hpp>
#include <Tools/Arguments/Maps/Argument_map_group.hpp>
#include <Tools/Arguments/Maps/Argument_map_info.hpp>
#include <Tools/Arguments/Maps/Argument_map_value.hpp>
#include <Tools/Arguments/Maps/Argument_tag.hpp>
#include <Tools/Arguments/Ranges/Argument_range.hpp>
#include <Tools/Arguments/Ranges/Function.hpp>
#include <Tools/Arguments/Ranges/Length.hpp>
#include <Tools/Arguments/Ranges/Max.hpp>
#include <Tools/Arguments/Ranges/Min.hpp>
#include <Tools/Arguments/Ranges/Negative.hpp>
#include <Tools/Arguments/Ranges/Non_zero.hpp>
#include <Tools/Arguments/Ranges/Positive.hpp>
#include <Tools/Arguments/Ranges/Set/Example_set.hpp>
#include <Tools/Arguments/Ranges/Set/Excluding_set.hpp>
#include <Tools/Arguments/Ranges/Set/Including_set.hpp>
#include <Tools/Arguments/Ranges/Set/Set.hpp>
#include <Tools/Arguments/Splitter/Splitter.hpp>
#include <Tools/Arguments/Types/Argument_type.hpp>
#include <Tools/Arguments/Types/Argument_type_limited.hpp>
#include <Tools/Arguments/Types/Container/List.hpp>
#include <Tools/Arguments/Types/Container/Text.hpp>
#include <Tools/Arguments/Types/File_system/File.hpp>
#include <Tools/Arguments/Types/File_system/File_system.hpp>
#include <Tools/Arguments/Types/File_system/Folder.hpp>
#include <Tools/Arguments/Types/File_system/Path.hpp>
#include <Tools/Arguments/Types/None.hpp>
#include <Tools/Arguments/Types/Number/Boolean.hpp>
#include <Tools/Arguments/Types/Number/Integer.hpp>
#include <Tools/Arguments/Types/Number/Real.hpp>
#include <Tools/Arguments/utilities.hpp>
#include <Tools/Code/BCH/BCH_polynomial_generator.hpp>
#include <Tools/Code/LDPC/AList/AList.hpp>
#include <Tools/Code/LDPC/Matrix_handler/LDPC_matrix_handler.hpp>
#include <Tools/Code/LDPC/QC/QC.hpp>
#include <Tools/Code/LDPC/Standard/DVBS2/DVBS2_constants.hpp>
#include <Tools/Code/LDPC/Standard/DVBS2/DVBS2_constants_16200.hpp>
#include <Tools/Code/LDPC/Standard/DVBS2/DVBS2_constants_64800.hpp>
#include <Tools/Code/LDPC/Syndrome/LDPC_syndrome.hpp>
#include <Tools/Code/LDPC/Update_rule/AMS/Update_rule_AMS.hpp>
#include <Tools/Code/LDPC/Update_rule/AMS/Update_rule_AMS_simd.hpp>
#include <Tools/Code/LDPC/Update_rule/LSPA/Update_rule_LSPA.hpp>
#include <Tools/Code/LDPC/Update_rule/LSPA/Update_rule_LSPA_simd.hpp>
#include <Tools/Code/LDPC/Update_rule/MS/Update_rule_MS.hpp>
#include <Tools/Code/LDPC/Update_rule/MS/Update_rule_MS_simd.hpp>
#include <Tools/Code/LDPC/Update_rule/NMS/Update_rule_NMS.hpp>
#include <Tools/Code/LDPC/Update_rule/NMS/Update_rule_NMS_simd.hpp>
#include <Tools/Code/LDPC/Update_rule/OMS/Update_rule_OMS.hpp>
#include <Tools/Code/LDPC/Update_rule/OMS/Update_rule_OMS_simd.hpp>
#include <Tools/Code/LDPC/Update_rule/SPA/Update_rule_SPA.hpp>
#include <Tools/Code/LDPC/Update_rule/SPA/Update_rule_SPA_simd.hpp>
#include <Tools/Code/Polar/API/API_polar.hpp>
#include <Tools/Code/Polar/API/API_polar_dynamic_inter.hpp>
#include <Tools/Code/Polar/API/API_polar_dynamic_inter_8bit_bitpacking.hpp>
#include <Tools/Code/Polar/API/API_polar_dynamic_intra.hpp>
#include <Tools/Code/Polar/API/API_polar_dynamic_seq.hpp>
#include <Tools/Code/Polar/API/API_polar_static_inter.hpp>
#include <Tools/Code/Polar/API/API_polar_static_inter_8bit_bitpacking.hpp>
#include <Tools/Code/Polar/API/API_polar_static_intra_16bit.hpp>
#include <Tools/Code/Polar/API/API_polar_static_intra_32bit.hpp>
#include <Tools/Code/Polar/API/API_polar_static_intra_8bit.hpp>
#include <Tools/Code/Polar/API/API_polar_static_seq.hpp>
#include <Tools/Code/Polar/Frozenbits_generator/Frozenbits_generator.hpp>
#include <Tools/Code/Polar/Frozenbits_generator/Frozenbits_generator_file.hpp>
#include <Tools/Code/Polar/Frozenbits_generator/Frozenbits_generator_GA.hpp>
#include <Tools/Code/Polar/Frozenbits_generator/Frozenbits_generator_TV.hpp>
#include <Tools/Code/Polar/Frozenbits_notifier.hpp>
#include <Tools/Code/Polar/Patterns/Pattern_polar_i.hpp>
#include <Tools/Code/Polar/Patterns/Pattern_polar_r0.hpp>
#include <Tools/Code/Polar/Patterns/Pattern_polar_r0_left.hpp>
#include <Tools/Code/Polar/Patterns/Pattern_polar_r1.hpp>
#include <Tools/Code/Polar/Patterns/Pattern_polar_rep.hpp>
#include <Tools/Code/Polar/Patterns/Pattern_polar_rep_left.hpp>
#include <Tools/Code/Polar/Patterns/Pattern_polar_spc.hpp>
#include <Tools/Code/Polar/Patterns/Pattern_polar_std.hpp>
#include <Tools/Code/Polar/Pattern_polar_parser.hpp>
#include <Tools/Code/RS/RS_polynomial_generator.hpp>
#include <Tools/Code/SCMA/modem_SCMA_functions.hpp>
#include <Tools/Code/Turbo/Post_processing_SISO/CRC/CRC_checker.hpp>
#include <Tools/Code/Turbo/Post_processing_SISO/CRC/CRC_checker_DB.hpp>
#include <Tools/Code/Turbo/Post_processing_SISO/Flip_and_check/Flip_and_check.hpp>
#include <Tools/Code/Turbo/Post_processing_SISO/Flip_and_check/Flip_and_check_DB.hpp>
#include <Tools/Code/Turbo/Post_processing_SISO/Post_processing_SISO.hpp>
#include <Tools/Code/Turbo/Post_processing_SISO/Scaling_factor/Scaling_factor.hpp>
#include <Tools/Code/Turbo/Post_processing_SISO/Scaling_factor/Scaling_factor_adaptive.hpp>
#include <Tools/Code/Turbo/Post_processing_SISO/Scaling_factor/Scaling_factor_array.hpp>
#include <Tools/Code/Turbo/Post_processing_SISO/Scaling_factor/Scaling_factor_constant.hpp>
#include <Tools/Code/Turbo/Post_processing_SISO/Scaling_factor/Scaling_factor_seq.hpp>
#include <Tools/Code/Turbo/Post_processing_SISO/Scaling_factor/Scaling_factor_vec.hpp>
#include <Tools/Code/Turbo/Post_processing_SISO/Self_corrected/Self_corrected.hpp>
#include <Tools/Display/Dumper/Dumper.hpp>
#include <Tools/Display/Dumper/Dumper_reduction.hpp>
#include <Tools/Display/Frame_trace/Frame_trace.hpp>
#include <Tools/Display/Reporter/BFER/Reporter_BFER.hpp>
#include <Tools/Display/Reporter/EXIT/Reporter_EXIT.hpp>
#include <Tools/Display/Reporter/MI/Reporter_MI.hpp>
#include <Tools/Display/Reporter/Noise/Reporter_noise.hpp>
#include <Tools/Display/Reporter/Reporter.hpp>
#include <Tools/Display/Reporter/Reporter_monitor.hpp>
#include <Tools/Display/Reporter/Throughput/Reporter_throughput.hpp>
#include <Tools/Display/Statistics/Statistics.hpp>
#include <Tools/Display/Terminal/Standard/Terminal_std.hpp>
#include <Tools/Display/Terminal/Terminal.hpp>
#include <Tools/Exception/cannot_allocate/cannot_allocate.hpp>
#include <Tools/Exception/domain_error/domain_error.hpp>
#include <Tools/Exception/exception.hpp>
#include <Tools/Exception/invalid_argument/invalid_argument.hpp>
#include <Tools/Exception/length_error/length_error.hpp>
#include <Tools/Exception/logic_error/logic_error.hpp>
#include <Tools/Exception/out_of_range/out_of_range.hpp>
#include <Tools/Exception/overflow_error/overflow_error.hpp>
#include <Tools/Exception/range_error/range_error.hpp>
#include <Tools/Exception/runtime_error/runtime_error.hpp>
#include <Tools/Exception/underflow_error/underflow_error.hpp>
#include <Tools/Exception/unimplemented_error/unimplemented_error.hpp>
#include <Tools/Interleaver/ARP/Interleaver_core_ARP_DVB_RCS1.hpp>
#include <Tools/Interleaver/ARP/Interleaver_core_ARP_DVB_RCS2.hpp>
#include <Tools/Interleaver/CCSDS/Interleaver_core_CCSDS.hpp>
#include <Tools/Interleaver/Column_row/Interleaver_core_column_row.hpp>
#include <Tools/Interleaver/Golden/Interleaver_core_golden.hpp>
#include <Tools/Interleaver/Interleaver_core.hpp>
#include <Tools/Interleaver/LTE/Interleaver_core_LTE.hpp>
#include <Tools/Interleaver/NO/Interleaver_core_NO.hpp>
#include <Tools/Interleaver/Random/Interleaver_core_random.hpp>
#include <Tools/Interleaver/Random_column/Interleaver_core_random_column.hpp>
#include <Tools/Interleaver/Row_column/Interleaver_core_row_column.hpp>
#include <Tools/Interleaver/User/Interleaver_core_user.hpp>
#include <Tools/Math/Distribution/Distribution.hpp>
#include <Tools/Math/Distribution/Distributions.hpp>
#include <Tools/Math/Galois.hpp>
#include <Tools/Noise/Event_probability.hpp>
#include <Tools/Noise/Noise.hpp>
#include <Tools/Noise/Received_optical_power.hpp>
#include <Tools/Noise/Sigma.hpp>
#include <Tools/Perf/Reorderer/Reorderer.hpp>
#include <Tools/SystemC/SC_Debug.hpp>
#include <Tools/SystemC/SC_Dummy.hpp>
#include <Tools/SystemC/SC_Duplicator.hpp>
#include <Tools/SystemC/SC_Funnel.hpp>
#include <Tools/SystemC/SC_Predicate.hpp>
#include <Tools/SystemC/SC_Router.hpp>
#include <Tools/Threads/Barrier.hpp>

#endif