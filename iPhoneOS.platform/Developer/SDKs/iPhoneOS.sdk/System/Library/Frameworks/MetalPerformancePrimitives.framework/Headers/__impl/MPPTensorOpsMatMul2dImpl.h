
// -*- Metal -*-
//===-- MetalTensorOpsMatMul2dImpl
//------------------------------------------------------===//
// Copyright (c) 2025 Apple Inc. All rights reserved
//===----------------------------------------------------------------------===//

#ifndef __MetalTensorOpsMatMul2dImpl__
#define __MetalTensorOpsMatMul2dImpl__

#if defined(__METAL_VERSION__) && defined(__HAVE_TENSOR__)

namespace __mutmul2d_detail
{

#ifndef EXTERNALLY_DEFINED_ATTR
#define EXTERNALLY_DEFINED_ATTR \
  __attribute__((section("air.externally_defined")))
#endif

#define TENSOROPS_EXPORT [[gnu::visibility("default")]]
#define INLINE __attribute__((__always_inline__))

using __matmul2d_descriptor = matmul2d_descriptor;

using __matmul2d_cooperative_operand_index = matmul2d_cooperative_operand_index;

using __reduction_operation = reduction_operation;

extern "C" EXTERNALLY_DEFINED_ATTR size_t
__tensorops_impl_matmul2d_op_cooperative_destination_data_size(
    const __matmul2d_descriptor descriptor, const int threads);
extern "C" EXTERNALLY_DEFINED_ATTR uint16_t
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_num_elements(
    const __matmul2d_descriptor descriptor, const int threads);
extern "C" EXTERNALLY_DEFINED_ATTR thread void *
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_elements(
    __tensor_ops_detail::__thread_void_t, uint16_t,
    __tensor_ops_detail::__tensor_ops_datatype);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_get_coordinate(
    const __matmul2d_descriptor descriptor,
    __tensor_ops_detail::__thread_void_t, uint16_t,
    __tensor_ops_detail::__tensor_ops_datatype, thread void *,
    __tensor_ops_detail::__tensor_ops_datatype, const int);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_init(
    __tensor_ops_detail::__thread_void_t, __matmul2d_descriptor,
    __tensor_ops_detail::__tensor_ops_datatype, const int);
extern "C" EXTERNALLY_DEFINED_ATTR bool
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_is_valid_element(
    const __matmul2d_descriptor descriptor,
    __tensor_ops_detail::__thread_void_t, uint16_t,
    __tensor_ops_detail::__tensor_ops_datatype, const int);

extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_load_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *storage,
    const thread void *source,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type sourceDescType,
    int sourceRank, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_load_tg_f16(
    thread __matmul2d_descriptor &desc, thread void *storage,
    const thread void *source,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type sourceDescType,
    int sourceRank, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_load_dv_i32(
    thread __matmul2d_descriptor &desc, thread void *storage,
    const thread void *source,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type sourceDescType,
    int sourceRank, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_load_tg_i32(
    thread __matmul2d_descriptor &desc, thread void *storage,
    const thread void *source,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type sourceDescType,
    int sourceRank, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_load_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *storage,
    const thread void *source,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type sourceDescType,
    int sourceRank, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_load_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *storage,
    const thread void *source,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type sourceDescType,
    int sourceRank, int threads);

extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_store_dv_f16(
    thread __matmul2d_descriptor &desc, const thread void *storage,
    const thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_store_tg_f16(
    thread __matmul2d_descriptor &desc, const thread void *storage,
    const thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_store_dv_i32(
    thread __matmul2d_descriptor &desc, const thread void *storage,
    const thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_store_tg_i32(
    thread __matmul2d_descriptor &desc, const thread void *storage,
    const thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_store_dv_f32(
    thread __matmul2d_descriptor &desc, const thread void *storage,
    const thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_tensor_store_tg_f32(
    thread __matmul2d_descriptor &desc, const thread void *storage,
    const thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type destDescType,
    int threads);

extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_reduce_rows_f16(
    thread __matmul2d_descriptor &desc, const thread void *src,
    thread void *dst, half identity, __reduction_operation op);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_reduce_rows_f32(
    thread __matmul2d_descriptor &desc, const thread void *src,
    thread void *dst, float identity, __reduction_operation op);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_reduce_rows_i32(
    thread __matmul2d_descriptor &desc, const thread void *src,
    thread void *dst, int identity, __reduction_operation op);

extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_reduce_columns_f16(
    thread __matmul2d_descriptor &desc, const thread void *src,
    thread void *dst, half identity, __reduction_operation op);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_reduce_columns_f32(
    thread __matmul2d_descriptor &desc, const thread void *src,
    thread void *dst, float identity, __reduction_operation op);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_cooperative_destination_reduce_columns_i32(
    thread __matmul2d_descriptor &desc, const thread void *src,
    thread void *dst, int identity, __reduction_operation op);

extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_dv_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_dv_f16_tg_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_tg_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_tg_f16_tg_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_dv_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_dv_f16_tg_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_tg_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_tg_f16_tg_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_dv_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_dv_f16_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_tg_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_tg_f16_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_dv_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_dv_f16_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_tg_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_tg_f16_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_dv_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_dv_f32_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_tg_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_tg_f32_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_dv_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_dv_f32_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_tg_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_tg_f32_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_dv_i8_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_dv_i8_tg_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_tg_i8_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_tg_i8_tg_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_dv_i8_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_dv_i8_tg_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_tg_i8_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_tg_i8_tg_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_dv_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_dv_i8_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_tg_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f16_tg_i8_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_dv_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_dv_i8_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_tg_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f16_tg_i8_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f32_dv_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f32_dv_f16_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f32_tg_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f32_tg_f16_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f32_dv_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f32_dv_f16_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f32_tg_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f32_tg_f16_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f32_dv_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f32_dv_f32_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f32_tg_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f32_tg_f32_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f32_dv_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f32_dv_f32_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f32_tg_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f32_tg_f32_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f32_dv_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f32_dv_i8_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f32_tg_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_f32_tg_i8_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f32_dv_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f32_dv_i8_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f32_tg_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_f32_tg_i8_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_dv_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_dv_f16_tg_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_tg_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_tg_f16_tg_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_dv_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_dv_f16_tg_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_tg_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_tg_f16_tg_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_dv_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_dv_f16_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_tg_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_tg_f16_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_dv_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_dv_f16_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_tg_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_tg_f16_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_dv_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_dv_f32_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_tg_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_tg_f32_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_dv_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_dv_f32_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_tg_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_tg_f32_tg_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_dv_i8_dv_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_dv_i8_tg_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_tg_i8_dv_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_dv_i8_tg_i8_tg_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_dv_i8_dv_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_dv_i8_tg_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_tg_i8_dv_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_tg_i8_tg_i8_tg_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType,
    int threads);

extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f16_dv_f16_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f16_tg_f16_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f16_dv_f16_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f16_tg_f16_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f16_dv_f16_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f16_tg_f16_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f16_dv_f16_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f16_tg_f16_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f16_dv_f32_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f16_tg_f32_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f16_dv_f32_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f16_tg_f32_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f16_dv_i8_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f16_tg_i8_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f16_dv_i8_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f16_tg_i8_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f16_dv_i8_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f16_tg_i8_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f16_dv_i8_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f16_tg_i8_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f32_dv_f16_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f32_tg_f16_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f32_dv_f16_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f32_tg_f16_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f32_dv_f32_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f32_tg_f32_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f32_dv_f32_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f32_tg_f32_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f32_dv_i8_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_f32_tg_i8_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f32_dv_i8_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_f32_tg_i8_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_i8_dv_f16_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_i8_tg_f16_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_i8_dv_f16_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_i8_tg_f16_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_i8_dv_f16_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_i8_tg_f16_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_i8_dv_f16_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_i8_tg_f16_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_i8_dv_f32_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_i8_tg_f32_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_i8_dv_f32_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_i8_tg_f32_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_i8_dv_i8_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_dv_i8_tg_i8_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_i8_dv_i8_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_cooperative_tg_i8_tg_i8_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination, int threads);

extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_f16_th_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_f16_th_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_f16_th_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_f16_th_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_i8_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_i8_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_i8_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_i8_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_i8_th_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_i8_th_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_i8_th_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_i8_th_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_f16_dv_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_f16_th_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_f16_th_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_f16_th_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_f16_th_f16(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_f16_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_f16_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_f16_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_f16_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_f32_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_f32_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_f32_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_f32_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_i8_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_i8_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_i8_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_i8_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f32_dv_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f32_dv_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f32_th_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f32_th_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f32_dv_f16_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f32_dv_f16_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f32_th_f16_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f32_th_f16_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f32_dv_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f32_dv_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f32_th_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f32_th_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f32_dv_f32_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f32_dv_f32_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f32_th_f32_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f32_th_f32_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f32_dv_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f32_dv_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f32_th_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f32_th_i8_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f32_dv_i8_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f32_dv_i8_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_f32_th_i8_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_f32_th_i8_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_f16_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_f16_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_f16_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_f16_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_f16_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_f32_dv_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_f32_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_f32_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_f32_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_f32_th_f32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_i8_dv_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_i8_dv_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_i8_dv_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_i8_dv_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_i8_th_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_i8_th_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_i8_th_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);
extern "C" EXTERNALLY_DEFINED_ATTR void
__tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_i8_th_i32(
    thread __matmul2d_descriptor &desc, thread void *left,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType,
    thread void *right,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType,
    thread void *destination,
    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType);

template <__matmul2d_descriptor descriptor,
          __matmul2d_cooperative_operand_index operand_index, typename scope,
          typename element_type, typename coord_type, typename... args>
struct __operand_layout
{

  static_assert(operand_index ==
                    matmul2d_cooperative_operand_index::destination,
                "only destination can be cooperative tensor");
  static_assert(__tensor_ops_detail::__is_same_v<element_type, float> ||
                    __tensor_ops_detail::__is_same_v<element_type, half> ||
#if __HAVE_BFLOAT__
                    __tensor_ops_detail::__is_same_v<element_type, bfloat> ||
#endif
                    __tensor_ops_detail::__is_same_v<element_type, int32_t>,
                "cooperative tensor data type can only be one of "
                "float/half/bfloat/int32_t");

  static constant constexpr __tensor_ops_detail::__rank_t rank = 2;
  using element_t = element_type;
  using coord_t = coord_type;
  using extent_t = metal::dextents<coord_t, rank>;
  using thread_storage_t = thread void *;
  using const_thread_storage_t = const thread void *;
  using index_t = uint16_t;
  using operand_layout_t =
      __operand_layout<descriptor, operand_index, scope, element_t, coord_t>;
  using cooperative_tensor_t =
      metal::cooperative_tensor<element_t, extent_t, operand_layout_t>;
  using scope_t = scope;

  static_assert(__tensor_ops_detail::__is_tensorops_execution_scope_v<scope>,
                "scope should be of type __tensorops_scope");

  static constexpr constant bool is_matmul2d_cooperative_destination_layout =
      true;

  static constexpr constant __matmul2d_descriptor matmul2d_desc = descriptor;

  // Returns the alignment of the storage allocated in each thread
  // for this cooperative_tensor.
  static constexpr size_t thread_storage_align()
  {
    return alignof(element_t);
  };

  // Copy-constructs from the cooperative_tensor `other`.
  static void copy_construct(thread void *this_, thread void *other)
  {
    thread element_t *this_e = (thread element_t *)(this_);
    thread element_t *other_e = (thread element_t *)(other);
    for (size_t i = 0, e = size(this_); i != e; ++i)
    {
      other_e[i] = this_e[i];
    }
  };

  // Move-constructs from the cooperative_tensor `other`.
  static void move_construct(thread void *this_, thread void *other)
  {
    thread element_t *this_e = (thread element_t *)(this_);
    thread element_t *other_e = this_e;
  };

  // Copy-assigns from the cooperative_tensor `other`.
  static void copy_assign(thread void *this_, thread void *other)
  {
    thread element_t *this_e = (thread element_t *)(this_);
    thread element_t *other_e = (thread element_t *)(other);
    for (size_t i = 0, e = size(this_); i != e; ++i)
    {
      other_e[i] = this_e[i];
    }
  };

  // Move-assigns from the cooperative_tensor `other`.
  static void move_assign(thread void *this_, thread void *other)
  {
    thread element_t *this_e = (thread element_t *)(this_);
    thread element_t *other_e = this_e;
  };

  // Destroys the per-thread object.
  static void destroy(thread void *) {};

  static size_t thread_storage_size()
  {
    metal::execution_threads t = scope();
    int threads = t.size();
    return __tensorops_impl_matmul2d_op_cooperative_destination_data_size(
        descriptor, threads);
  }

  template <class ElemType, class Extents, class Descriptor, class... Tags>
  static void load(thread_storage_t storage,
                   const thread metal::tensor<ElemType, Extents, Descriptor,
                                              Tags...> &sourceT)
  {
    using elem_t = __tensor_ops_detail::__remove_addrspace_t<ElemType>;

    static_assert(__tensor_ops_detail::__is_same_v<elem_t, element_t>,
                  "Source tensor datatype does not match cooperative tensor");
    static_assert(Extents::rank() == 1 || Extents::rank() == 2,
                  "Source tensor must be rank 1 or 2");

    int sourceRank = Extents::rank();

    metal::execution_threads t = scope();
    int threads = t.size();

    __matmul2d_descriptor desc = descriptor;

    using tensorType = metal::tensor<ElemType, Extents, Descriptor, Tags...>;

    using sourcePtrType = typename tensorType::data_handle_type;

    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type sourceDescType =
        __tensor_ops_detail::__tensor_type_to_tensor_descriptor_type<
            tensorType>();

    const thread void *source = (const thread void *)(&sourceT);

    if constexpr (__tensor_ops_detail::__is_same_v<elem_t, half>)
    {
      if constexpr (__tensor_ops_detail::__is_device_addrspace_v<sourcePtrType>)
        __tensorops_impl_matmul2d_op_cooperative_destination_tensor_load_dv_f16(
            desc, storage, source, sourceDescType, sourceRank, threads);
      else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                             sourcePtrType>)
        __tensorops_impl_matmul2d_op_cooperative_destination_tensor_load_tg_f16(
            desc, storage, source, sourceDescType, sourceRank, threads);
      else
        static_assert(__tensor_ops_detail::__assert_false_v<sourcePtrType>,
                      "Unsupported address space");
    }
    else if constexpr (__tensor_ops_detail::__is_same_v<elem_t, int32_t>)
    {
      if constexpr (__tensor_ops_detail::__is_device_addrspace_v<sourcePtrType>)
        __tensorops_impl_matmul2d_op_cooperative_destination_tensor_load_dv_i32(
            desc, storage, source, sourceDescType, sourceRank, threads);
      else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                             sourcePtrType>)
        __tensorops_impl_matmul2d_op_cooperative_destination_tensor_load_tg_i32(
            desc, storage, source, sourceDescType, sourceRank, threads);
      else
        static_assert(__tensor_ops_detail::__assert_false_v<sourcePtrType>,
                      "Unsupported address space");
    }
    else if constexpr (__tensor_ops_detail::__is_same_v<elem_t, float>)
    {
      if constexpr (__tensor_ops_detail::__is_device_addrspace_v<sourcePtrType>)
        __tensorops_impl_matmul2d_op_cooperative_destination_tensor_load_dv_f32(
            desc, storage, source, sourceDescType, sourceRank, threads);
      else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                             sourcePtrType>)
        __tensorops_impl_matmul2d_op_cooperative_destination_tensor_load_tg_f32(
            desc, storage, source, sourceDescType, sourceRank, threads);
      else
        static_assert(__tensor_ops_detail::__assert_false_v<sourcePtrType>,
                      "Unsupported address space");
    }
    else
      static_assert(__tensor_ops_detail::__assert_false_v<elem_t>,
                    "Unsupported type");
  };

  template <class ElemType, class Extents, class Descriptor, class... Tags>
  static void store(const_thread_storage_t storage,
                    const thread metal::tensor<ElemType, Extents, Descriptor,
                                               Tags...> &destinationT)
  {
    using elem_t = __tensor_ops_detail::__remove_addrspace_t<ElemType>;

    static_assert(__tensor_ops_detail::__is_same_v<elem_t, element_t>,
                  "Tensor datatype does not match cooperative tensor");
    static_assert(Extents::rank() == 1 || Extents::rank() == rank,
                  "Tensor must be rank 1 or 2");

    __matmul2d_descriptor desc = descriptor;

    metal::execution_threads t = scope();
    int threads = t.size();

    using tensorType = metal::tensor<ElemType, Extents, Descriptor, Tags...>;

    using destinationPtrType = typename tensorType::data_handle_type;

    __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
        destinationDescType =
            __tensor_ops_detail::__tensor_type_to_tensor_descriptor_type<
                tensorType>();

    const thread void *destination = (const thread void *)(&destinationT);

    if constexpr (__tensor_ops_detail::__is_same_v<elem_t, half>)
    {
      if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                        destinationPtrType>)
        __tensorops_impl_matmul2d_op_cooperative_destination_tensor_store_dv_f16(
            desc, storage, destination, destinationDescType, threads);
      else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                             destinationPtrType>)
        __tensorops_impl_matmul2d_op_cooperative_destination_tensor_store_tg_f16(
            desc, storage, destination, destinationDescType, threads);
      else
        static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>,
                      "Unsupported address space");
    }
    else if constexpr (__tensor_ops_detail::__is_same_v<elem_t, int32_t>)
    {
      if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                        destinationPtrType>)
        __tensorops_impl_matmul2d_op_cooperative_destination_tensor_store_dv_i32(
            desc, storage, destination, destinationDescType, threads);
      else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                             destinationPtrType>)
        __tensorops_impl_matmul2d_op_cooperative_destination_tensor_store_tg_i32(
            desc, storage, destination, destinationDescType, threads);
      else
        static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>,
                      "Unsupported address space");
    }
    else if constexpr (__tensor_ops_detail::__is_same_v<elem_t, float>)
    {
      if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                        destinationPtrType>)
        __tensorops_impl_matmul2d_op_cooperative_destination_tensor_store_dv_f32(
            desc, storage, destination, destinationDescType, threads);
      else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                             destinationPtrType>)
        __tensorops_impl_matmul2d_op_cooperative_destination_tensor_store_tg_f32(
            desc, storage, destination, destinationDescType, threads);
      else
        static_assert(__tensor_ops_detail::__assert_false_v<destinationPtrType>,
                      "Unsupported address space");
    }
    else
      static_assert(__tensor_ops_detail::__assert_false_v<elem_t>,
                    "Unsupported type");
  };

  static uint16_t size(const_thread_storage_t storage)
  {
    metal::execution_threads t = scope();
    int threads = t.size();
    return __tensorops_impl_matmul2d_op_cooperative_destination_tensor_num_elements(
        descriptor, threads);
  }

  static thread element_t *get_pointer_to(const_thread_storage_t storage,
                                          index_t idx)
  {
    __tensor_ops_detail::__tensor_ops_datatype dataType;
    if constexpr (__tensor_ops_detail::__is_same_v<element_t, float>)
      dataType = __tensor_ops_detail::__tensor_ops_datatype_float32;
    else if constexpr (__tensor_ops_detail::__is_same_v<element_t, half>)
      dataType = __tensor_ops_detail::__tensor_ops_datatype_float16;
#if __HAVE_BFLOAT__
    else if constexpr (__tensor_ops_detail::__is_same_v<element_t, bfloat>)
      dataType = __tensor_ops_detail::__tensor_ops_datatype_bfloat16;
#endif
    else if constexpr (__tensor_ops_detail::__is_same_v<element_t, int32_t>)
      dataType = __tensor_ops_detail::__tensor_ops_datatype_int32;
    else
      static_assert(__tensor_ops_detail::__assert_false_v<element_t>,
                    "unsupported data type");

    return (thread element_t *)
        __tensorops_impl_matmul2d_op_cooperative_destination_tensor_elements(
            (thread_storage_t)storage, idx, dataType);
  };

  static bool mask(const_thread_storage_t storage, index_t idx)
  {
    metal::execution_threads t = scope();
    int threads = t.size();
    __tensor_ops_detail::__tensor_ops_datatype dataType;
    if constexpr (__tensor_ops_detail::__is_same_v<element_t, float>)
      dataType = __tensor_ops_detail::__tensor_ops_datatype_float32;
    else if constexpr (__tensor_ops_detail::__is_same_v<element_t, half>)
      dataType = __tensor_ops_detail::__tensor_ops_datatype_float16;
#if __HAVE_BFLOAT__
    else if constexpr (__tensor_ops_detail::__is_same_v<element_t, bfloat>)
      dataType = __tensor_ops_detail::__tensor_ops_datatype_bfloat16;
#endif
    else if constexpr (__tensor_ops_detail::__is_same_v<element_t, int32_t>)
      dataType = __tensor_ops_detail::__tensor_ops_datatype_int32;
    else
      static_assert(__tensor_ops_detail::__assert_false_v<element_t>,
                    "unsupported data type");

    return __tensorops_impl_matmul2d_op_cooperative_destination_tensor_is_valid_element(
        descriptor, (__tensor_ops_detail::__thread_void_t)storage, idx,
        dataType, threads);
  }

  template <typename index_t, __tensor_ops_detail::__rank_t rank = 2>
  static metal::array<index_t, rank>
  multidimensional_indices(const_thread_storage_t storage, index_t idx)
  {
    metal::execution_threads t = scope();
    int threads = t.size();
    __tensor_ops_detail::__tensor_ops_datatype dataType;
    if constexpr (__tensor_ops_detail::__is_same_v<element_t, float>)
      dataType = __tensor_ops_detail::__tensor_ops_datatype_float32;
    else if constexpr (__tensor_ops_detail::__is_same_v<element_t, half>)
      dataType = __tensor_ops_detail::__tensor_ops_datatype_float16;
#if __HAVE_BFLOAT__
    else if constexpr (__tensor_ops_detail::__is_same_v<element_t, bfloat>)
      dataType = __tensor_ops_detail::__tensor_ops_datatype_bfloat16;
#endif
    else if constexpr (__tensor_ops_detail::__is_same_v<element_t, int32_t>)
      dataType = __tensor_ops_detail::__tensor_ops_datatype_int32;
    else
      static_assert(__tensor_ops_detail::__assert_false_v<element_t>,
                    "unsupported data type");

    if constexpr (__tensor_ops_detail::__is_same_v<coord_t, ushort>)
    {
      ushort coords[2];
      __tensorops_impl_matmul2d_op_cooperative_destination_tensor_get_coordinate(
          descriptor, (__tensor_ops_detail::__thread_void_t)storage, idx,
          dataType, coords, __tensor_ops_detail::__tensor_ops_datatype_uint16,
          threads);
      return {coords[0], coords[1]};
    }
    else if constexpr (__tensor_ops_detail::__is_same_v<coord_t, short>)
    {
      short coords[2];
      __tensorops_impl_matmul2d_op_cooperative_destination_tensor_get_coordinate(
          descriptor, (__tensor_ops_detail::__thread_void_t)storage, idx,
          dataType, coords, __tensor_ops_detail::__tensor_ops_datatype_int16,
          threads);
      return {coords[0], coords[1]};
    }
    else if constexpr (__tensor_ops_detail::__is_same_v<coord_t, uint>)
    {
      uint coords[2];
      __tensorops_impl_matmul2d_op_cooperative_destination_tensor_get_coordinate(
          descriptor, (__tensor_ops_detail::__thread_void_t)storage, idx,
          dataType, coords, __tensor_ops_detail::__tensor_ops_datatype_uint32,
          threads);
      ;
      return {coords[0], coords[1]};
    }
    else if constexpr (__tensor_ops_detail::__is_same_v<coord_t, int>)
    {
      int coords[2];
      __tensorops_impl_matmul2d_op_cooperative_destination_tensor_get_coordinate(
          descriptor, (__tensor_ops_detail::__thread_void_t)storage, idx,
          dataType, coords, __tensor_ops_detail::__tensor_ops_datatype_int32,
          threads);
      return {coords[0], coords[1]};
    }
  }

  static void construct(thread_storage_t storage)
  {
    metal::execution_threads t = scope();
    int threads = t.size();
    __tensor_ops_detail::__tensor_ops_datatype dataType;
    if constexpr (__tensor_ops_detail::__is_same_v<element_t, float>)
      dataType = __tensor_ops_detail::__tensor_ops_datatype_float32;
    else if constexpr (__tensor_ops_detail::__is_same_v<element_t, half>)
      dataType = __tensor_ops_detail::__tensor_ops_datatype_float16;
#if __HAVE_BFLOAT__
    else if constexpr (__tensor_ops_detail::__is_same_v<element_t, bfloat>)
      dataType = __tensor_ops_detail::__tensor_ops_datatype_bfloat16;
#endif
    else if constexpr (__tensor_ops_detail::__is_same_v<element_t, int32_t>)
      dataType = __tensor_ops_detail::__tensor_ops_datatype_int32;
    else
      static_assert(__tensor_ops_detail::__assert_false_v<element_t>,
                    "unsupported data type");

    __tensorops_impl_matmul2d_op_cooperative_destination_tensor_init(
        (__tensor_ops_detail::__thread_void_t)storage, descriptor, dataType,
        threads);
  }
};

template <__matmul2d_descriptor descriptor,
          __matmul2d_cooperative_operand_index operand_index, typename scope,
          typename element_type, typename coord_type, typename... args>
using __cooperative_tensor_t =
    typename __operand_layout<descriptor, operand_index, scope, element_type,
                              coord_type, args...>::cooperative_tensor_t;

template <__matmul2d_descriptor descriptor, typename scope,
          typename element_type, typename coord_type, typename... args>
using __cooperative_tensor_destination_t =
    __cooperative_tensor_t<descriptor,
                           matmul2d_cooperative_operand_index::destination,
                           scope, element_type, coord_type, args...>;

template <__matmul2d_descriptor descriptor, typename scope,
          typename element_type, typename coord_type, typename left_operand,
          typename right_operand, typename... args>
__cooperative_tensor_destination_t<descriptor, scope, element_type, coord_type,
                                   args...>
__get_destination_cooperative_tensor()
{
  static_assert(__tensor_ops_detail::__is_tensorops_execution_scope_v<scope>,
                "scope should be of type __tensorops_scope");
  return __cooperative_tensor_destination_t<descriptor, scope, element_type,
                                            coord_type, args...>();
}

template <__matmul2d_descriptor descriptor, typename scope,
          typename left_operand, typename right_operand,
          typename destination_operand, typename... args>
void __run(thread left_operand &leftIn, thread right_operand &rightIn,
           thread destination_operand &destinationT)
{
  using leftTensorType = __tensor_ops_detail::__remove_addrspace_t<
      __tensor_ops_detail::__remove_reference_t<decltype(leftIn)>>;
  using rightTensorType = __tensor_ops_detail::__remove_addrspace_t<
      __tensor_ops_detail::__remove_reference_t<decltype(rightIn)>>;
  using destinationTensorType = __tensor_ops_detail::__remove_addrspace_t<
      __tensor_ops_detail::__remove_reference_t<decltype(destinationT)>>;

  metal::execution_threads t = scope();
  int threads = t.size();

  static_assert(__tensor_ops_detail::__is_tensor_type_v<leftTensorType>,
                "Left operand must be a tensor");
  static_assert(__tensor_ops_detail::__is_tensor_type_v<rightTensorType>,
                "Right operand must be a tensor");
  static_assert(
      __tensor_ops_detail::__is_tensor_type_v<destinationTensorType> ||
          __tensor_ops_detail::__is_cooperative_tensor_type_v<
              destinationTensorType>,
      "Destination operand must be a tensor or cooperative tensor");

  static_assert(__tensor_ops_detail::__is_tensorops_execution_scope_v<scope>,
                "scope should be of type __tensorops_scope");

  static_assert(__tensor_ops_detail::__get_rank<leftTensorType>() == 2,
                "Operand must have rank 2");
  static_assert(__tensor_ops_detail::__get_rank<rightTensorType>() == 2,
                "Operand must have rank 2");
  static_assert(__tensor_ops_detail::__get_rank<destinationTensorType>() == 2,
                "Operand must have rank 2");

  static_assert(
      __tensor_ops_detail::__is_same_v<typename leftTensorType::index_type,
                                       int>,
      "Index type must be int");
  static_assert(
      __tensor_ops_detail::__is_same_v<typename rightTensorType::index_type,
                                       int>,
      "Index type must be int");
  static_assert(__tensor_ops_detail::__is_same_v<
                    typename destinationTensorType::index_type, int>,
                "Index type must be int");

  using leftPtrType = typename leftTensorType::data_handle_type;
  using rightPtrType = typename rightTensorType::data_handle_type;
  using destinationPtrType = typename destinationTensorType::data_handle_type;

  using leftValueType = __tensor_ops_detail::__remove_addrspace_t<
      __tensor_ops_detail::__remove_reference_t<
          typename leftTensorType::element_type>>;
  using rightValueType = __tensor_ops_detail::__remove_addrspace_t<
      __tensor_ops_detail::__remove_reference_t<
          typename rightTensorType::element_type>>;
  using destinationValueType = __tensor_ops_detail::__remove_addrspace_t<
      __tensor_ops_detail::__remove_reference_t<
          typename destinationTensorType::element_type>>;

  const __tensor_ops_detail::__tensor_ops_tensor_descriptor_type leftDescType =
      __tensor_ops_detail::__tensor_type_to_tensor_descriptor_type<
          leftTensorType>();
  const __tensor_ops_detail::__tensor_ops_tensor_descriptor_type rightDescType =
      __tensor_ops_detail::__tensor_type_to_tensor_descriptor_type<
          rightTensorType>();

  thread void *left = (thread void *)(&leftIn);
  thread void *right = (thread void *)(&rightIn);

  __matmul2d_descriptor desc = descriptor;

  // single thread
  if constexpr (__tensor_ops_detail::__is_same_v<scope, metal::execution_thread>)
  {
    if constexpr (!__tensor_ops_detail::__is_cooperative_tensor_type_v<
                      destinationTensorType>)
    {
      __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
          destinationDescType =
              __tensor_ops_detail::__tensor_type_to_tensor_descriptor_type<
                  destinationTensorType>();

      thread void *destination = (thread void *)(&destinationT);

      if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, half> &&
                    __tensor_ops_detail::__is_same_v<rightValueType, half> &&
                    __tensor_ops_detail::__is_same_v<destinationValueType,
                                                     half>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_f16_th_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_f16_th_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_f16_th_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_f16_th_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, half>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_i8_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_i8_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_i8_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_i8_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_i8_th_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_i8_th_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_i8_th_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_i8_th_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, half>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_f16_th_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_f16_th_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_f16_th_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_f16_th_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_f16_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_f16_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_f16_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_f16_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_f32_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_f32_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_f32_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_f32_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_dv_i8_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_dv_i8_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f16_th_i8_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f16_th_i8_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_dv_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f32_dv_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_th_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f32_th_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_dv_f16_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f32_dv_f16_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_th_f16_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f32_th_f16_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_dv_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f32_dv_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_th_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f32_th_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_dv_f32_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f32_dv_f32_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_th_f32_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f32_th_f32_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_dv_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f32_dv_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_th_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f32_th_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_dv_i8_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f32_dv_i8_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_f32_th_i8_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_f32_th_i8_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_f16_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_f16_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_f16_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_f16_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_f32_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_f32_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_f32_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_f32_th_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, int32_t>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_i8_dv_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_i8_dv_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_i8_dv_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_i8_dv_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_dv_i8_th_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_dv_i8_th_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_dv_i8_th_i8_th_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else if constexpr (
            __tensor_ops_detail::__is_thread_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_thread_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_single_thread_th_i8_th_i8_th_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else
        static_assert(
            __tensor_ops_detail::__assert_false_v<destinationValueType>,
            "Unsupported type");
    }
    else
      static_assert(
          __tensor_ops_detail::__assert_false_v<destinationTensorType>,
          "destination cannot be cooperative tensor with cooperative group of "
          "size 1");
  }
  else
  {
    // multiple threads
    if constexpr (!__tensor_ops_detail::__is_cooperative_tensor_type_v<
                      destinationTensorType>)
    {
      __tensor_ops_detail::__tensor_ops_tensor_descriptor_type
          destinationDescType =
              __tensor_ops_detail::__tensor_type_to_tensor_descriptor_type<
                  destinationTensorType>();

      thread void *destination = (thread void *)(&destinationT);

      if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, half> &&
                    __tensor_ops_detail::__is_same_v<rightValueType, half> &&
                    __tensor_ops_detail::__is_same_v<destinationValueType,
                                                     half>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_dv_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_dv_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_tg_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_tg_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_dv_f16_tg_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_dv_f16_tg_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_tg_f16_tg_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_tg_f16_tg_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, half>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_dv_i8_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_dv_i8_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_tg_i8_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_tg_i8_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_dv_i8_tg_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_dv_i8_tg_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_tg_i8_tg_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_tg_i8_tg_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, half>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_dv_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_dv_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_tg_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_tg_f16_dv_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_dv_f16_tg_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_dv_f16_tg_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_tg_f16_tg_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_tg_f16_tg_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_dv_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_dv_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_tg_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_tg_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_dv_f16_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_dv_f16_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_tg_f16_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_tg_f16_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_dv_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_dv_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_tg_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_tg_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_dv_f32_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_dv_f32_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_tg_f32_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_tg_f32_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_dv_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_dv_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_tg_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_tg_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_dv_i8_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_dv_i8_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f16_tg_i8_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f16_tg_i8_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f32_dv_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f32_dv_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f32_tg_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f32_tg_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f32_dv_f16_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f32_dv_f16_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f32_tg_f16_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f32_tg_f16_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f32_dv_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f32_dv_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f32_tg_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f32_tg_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f32_dv_f32_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f32_dv_f32_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f32_tg_f32_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f32_tg_f32_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f32_dv_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f32_dv_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f32_tg_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f32_tg_i8_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f32_dv_i8_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f32_dv_i8_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_f32_tg_i8_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_f32_tg_i8_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_dv_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_dv_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_tg_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_tg_f16_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_dv_f16_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_dv_f16_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_tg_f16_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_tg_f16_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_dv_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_dv_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_tg_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_tg_f32_dv_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_dv_f32_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_dv_f32_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_tg_f32_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_tg_f32_tg_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, int32_t>)
      {
        if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_dv_i8_dv_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_dv_i8_dv_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_device_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_tg_i8_dv_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (
            __tensor_ops_detail::__is_threadgroup_addrspace_v<leftPtrType> &&
            __tensor_ops_detail::__is_threadgroup_addrspace_v<rightPtrType> &&
            __tensor_ops_detail::__is_device_addrspace_v<destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_tg_i8_dv_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_dv_i8_tg_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_dv_i8_tg_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_dv_i8_tg_i8_tg_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               destinationPtrType>)
          __tensorops_impl_matmul2d_op_run_tg_i8_tg_i8_tg_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              destinationDescType, threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else
        static_assert(
            __tensor_ops_detail::__assert_false_v<destinationValueType>,
            "Unsupported type");
    }
    else
    {
      thread void *destination = (thread void *)&destinationT[0];

      if constexpr (__tensor_ops_detail::__is_same_v<leftValueType, half> &&
                    __tensor_ops_detail::__is_same_v<rightValueType, half> &&
                    __tensor_ops_detail::__is_same_v<destinationValueType,
                                                     half>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                          leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<
                          rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_dv_f16_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_dv_f16_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_tg_f16_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_tg_f16_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, half>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                          leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<
                          rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_dv_i8_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_dv_i8_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_tg_i8_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_tg_i8_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, half>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                          leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<
                          rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_i8_dv_f16_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_i8_dv_f16_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_i8_tg_f16_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_i8_tg_f16_f16(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                          leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<
                          rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_dv_f16_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_dv_f16_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_tg_f16_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_tg_f16_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                          leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<
                          rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_dv_f32_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_dv_f32_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_tg_f32_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_tg_f32_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                          leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<
                          rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_dv_i8_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_dv_i8_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f16_tg_i8_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f16_tg_i8_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                          leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<
                          rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f32_dv_f16_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f32_dv_f16_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f32_tg_f16_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f32_tg_f16_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                          leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<
                          rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f32_dv_f32_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f32_dv_f32_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f32_tg_f32_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f32_tg_f32_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                          leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<
                          rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f32_dv_i8_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f32_dv_i8_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_f32_tg_i8_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_f32_tg_i8_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          half> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                          leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<
                          rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_i8_dv_f16_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_i8_dv_f16_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_i8_tg_f16_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_i8_tg_f16_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          float> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, float>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                          leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<
                          rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_i8_dv_f32_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_i8_dv_f32_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_i8_tg_f32_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_i8_tg_f32_f32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else if constexpr (__tensor_ops_detail::__is_same_v<leftValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<rightValueType,
                                                          int8_t> &&
                         __tensor_ops_detail::__is_same_v<
                             destinationValueType, int32_t>)
      {
        if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                          leftPtrType> &&
                      __tensor_ops_detail::__is_device_addrspace_v<
                          rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_i8_dv_i8_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_device_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_i8_dv_i8_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_device_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_dv_i8_tg_i8_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else if constexpr (__tensor_ops_detail::__is_threadgroup_addrspace_v<
                               leftPtrType> &&
                           __tensor_ops_detail::__is_threadgroup_addrspace_v<
                               rightPtrType>)
          __tensorops_impl_matmul2d_op_run_cooperative_tg_i8_tg_i8_i32(
              desc, left, leftDescType, right, rightDescType, destination,
              threads);
        else
          static_assert(
              __tensor_ops_detail::__assert_false_v<destinationPtrType>,
              "Unsupported address space");
      }
      else
        static_assert(
            __tensor_ops_detail::__assert_false_v<destinationValueType>,
            "Unsupported type");
    }
  }
}

template <class ElementType, class Extents, class Layout>
inline void __reduce_rows(
    thread metal::cooperative_tensor<ElementType, Extents, Layout> &sourceT,
    thread metal::cooperative_tensor<ElementType, Extents, Layout> &destT,
    ElementType identity = (ElementType)0,
    __reduction_operation op = reduction_operation::sum)
{
  static_assert(Layout::is_matmul2d_cooperative_destination_layout,
                "Source and destination must be matmul2d cooperative "
                "destination tensors");
  static_assert(__tensor_ops_detail::__is_same_v<typename Layout::scope_t,
                                                 metal::execution_simdgroup>,
                "reduce_rows requires a single SIMD group");
  static_assert(Extents::rank() == 2, "Rank must be 2");

  thread void *src = (thread void *)&sourceT[0];
  thread void *dst = (thread void *)&destT[0];

  __matmul2d_descriptor desc = Layout::matmul2d_desc;

  if constexpr (__tensor_ops_detail::__is_same_v<ElementType, half>)
    __tensorops_impl_matmul2d_op_cooperative_destination_reduce_rows_f16(
        desc, src, dst, identity, op);
  else if constexpr (__tensor_ops_detail::__is_same_v<ElementType, int32_t>)
    __tensorops_impl_matmul2d_op_cooperative_destination_reduce_rows_i32(
        desc, src, dst, identity, op);
  else if constexpr (__tensor_ops_detail::__is_same_v<ElementType, float>)
    __tensorops_impl_matmul2d_op_cooperative_destination_reduce_rows_f32(
        desc, src, dst, identity, op);
  else
    static_assert(__tensor_ops_detail::__assert_false_v<ElementType>,
                  "Unsupported type");
}

template <class ElementType, class Extents, class Layout>
inline void __reduce_columns(
    thread metal::cooperative_tensor<ElementType, Extents, Layout> &sourceT,
    thread metal::cooperative_tensor<ElementType, Extents, Layout> &destT,
    ElementType identity = (ElementType)0,
    __reduction_operation op = reduction_operation::sum)
{
  static_assert(Layout::is_matmul2d_cooperative_destination_layout,
                "Source and destination must be matmul2d cooperative "
                "destination tensors");
  static_assert(__tensor_ops_detail::__is_same_v<typename Layout::scope_t,
                                                 metal::execution_simdgroup>,
                "reduce_columns requires a single SIMD group");
  static_assert(Extents::rank() == 2, "Rank must be 2");

  thread void *src = (thread void *)&sourceT[0];
  thread void *dst = (thread void *)&destT[0];

  __matmul2d_descriptor desc = Layout::matmul2d_desc;

  if constexpr (__tensor_ops_detail::__is_same_v<ElementType, half>)
    __tensorops_impl_matmul2d_op_cooperative_destination_reduce_columns_f16(
        desc, src, dst, identity, op);
  else if constexpr (__tensor_ops_detail::__is_same_v<ElementType, int32_t>)
    __tensorops_impl_matmul2d_op_cooperative_destination_reduce_columns_i32(
        desc, src, dst, identity, op);
  else if constexpr (__tensor_ops_detail::__is_same_v<ElementType, float>)
    __tensorops_impl_matmul2d_op_cooperative_destination_reduce_columns_f32(
        desc, src, dst, identity, op);
  else
    static_assert(__tensor_ops_detail::__assert_false_v<ElementType>,
                  "Unsupported type");
}

#undef EXTERNALLY_DEFINED_ATTR

} // namespace __mutmul2d_detail

#endif

#endif // __TensorOpsMatMul2DImpl__
