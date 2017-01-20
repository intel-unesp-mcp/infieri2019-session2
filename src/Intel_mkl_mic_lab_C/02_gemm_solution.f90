! 
!  Copyright 2003-2013 Intel Corporation. All Rights Reserved.
!  
!  The source code contained or described herein and all documents related 
!  to the source code ("Material") are owned by Intel Corporation or its
!  suppliers or licensors.  Title to the Material remains with Intel Corporation
!  or its suppliers and licensors.  The Material is protected by worldwide
!  copyright and trade secret laws and treaty provisions.  No part of the
!  Material may be used, copied, reproduced, modified, published, uploaded,
!  posted, transmitted, distributed, or disclosed in any way without Intel's
!  prior express written permission.
!  
!  No license under any patent, copyright, trade secret or other intellectual
!  property right is granted to or conferred upon you by disclosure or delivery
!  of the Materials, either expressly, by implication, inducement, estoppel
!  or otherwise.  Any license under such intellectual property rights must
!  be express and approved by Intel in writing.
! 


!dec$ attributes offload:mic    :: sgemm_fortran_solution
!dec$ attributes C              :: sgemm_fortran_solution
subroutine sgemm_fortran_solution(r, a, b, arows, acols, bcols)
    implicit none
    integer :: arows, acols, bcols
    real(kind=4)    , intent(out)   :: r(0:arows*bcols-1)
    real(kind=4)    , intent(in)    :: a(0:arows*acols-1)
    real(kind=4)    , intent(in)    :: b(0:acols*bcols-1)
    integer :: i, k, r0, a0, b0, w

    !$omp parallel do private(i,k,r0,a0,b0,w)
    do i = 0, arows - 1
        w = bcols - 1
        r0 = i * bcols
        a0 = i * acols
        r(r0:r0+w) = 0

        do k = 0, acols - 1
            b0 = k * bcols
            r(r0:r0+w) = r(r0:r0+w) + a(a0+k) * b(b0:b0+w)
        enddo
    enddo
end subroutine


!dec$ attributes offload:mic    :: dgemm_fortran_solution
!dec$ attributes C              :: dgemm_fortran_solution
subroutine dgemm_fortran_solution(r, a, b, arows, acols, bcols)
    implicit none
    integer :: arows, acols, bcols
    real(kind=8)    , intent(out)   :: r(0:arows*bcols-1)
    real(kind=8)    , intent(in)    :: a(0:arows*acols-1)
    real(kind=8)    , intent(in)    :: b(0:acols*bcols-1)
    integer :: i, k, r0, a0, b0, w

    !$omp parallel do private(i,k,r0,a0,b0,w)
    do i = 0, arows - 1
        w = bcols - 1
        r0 = i * bcols
        a0 = i * acols
        r(r0:r0+w) = 0

        do k = 0, acols - 1
            b0 = k * bcols
            r(r0:r0+w) = r(r0:r0+w) + a(a0+k) * b(b0:b0+w)
        enddo
    enddo
end subroutine
