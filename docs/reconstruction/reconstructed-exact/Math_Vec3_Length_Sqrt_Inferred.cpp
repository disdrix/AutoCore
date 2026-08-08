// =============================================================================
// Math_Vec3_Length_Sqrt_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00404c00
// Address:   0x00404c00 – 0x00404c20 inclusive (33 B / 0x21)
// Module:    autoassault.exe (image base 0x400000)
// System:    math / vec3 length
// Dual:      MEGA-060 2026-08-05 (decompile + disassemble_function + read_memory
//            + callers/xrefs). No disassemble_bytes. No Launcher.
// Exactness: Behavior-preserving rewrite of decompiler/machine control flow.
//            Not modernization. Not bit-exact certified.
// Ghidra:    FUN_00404c00
// Retired:   Named_CalleeOf_Mission_Look_in_your_Mission_Inventory_00404c00
//            (parent plate only; body is pure length, not mission inventory).
// =============================================================================
//
// PURPOSE:
//   Euclidean length of a contiguous float3 pointed by ECX:
//     return sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
//   Leaf: hardware FSQRT; no CALLs; no stores.
//
// ABI (machine):
//   ECX = const float *v   // x@+0, y@+4, z@+8
//   return ST0 (x87; decompiler float10)
//   RET (C3) — no stack args / no callee stack cleanup
//
// CALLERS (5 UNCONDITIONAL_CALL / 4 functions):
//   FUN_00500560 @ 0x00501257
//   FUN_005a75f0 @ 0x005a77e0
//   FUN_005ba440 @ 0x005bace8
//   FUN_008a8770 (Mission_Look_in_your_Mission_Inventory) @ 0x008a8cd0, 0x008a8d5e
// =============================================================================

// Ghidra name: FUN_00404c00
// Readable restatement of the x87 leaf. Retail uses ECX + ST0, not a C ABI.
// Prefer <cmath> sqrtf for host ports; keep formula bit-order free (sums commute).

double Math_Vec3_Length_Sqrt_Inferred(const float *v /* ECX */)
{
  // Machine load order is z, y, x; product sum is identical:
  //   FLD [ECX+8]; FLD [ECX+4]; FLD [ECX]
  //   x*x + y*y + z*z ; FSQRT ; leave result in ST0
  const double x = static_cast<double>(v[0]);
  const double y = static_cast<double>(v[1]);
  const double z = static_cast<double>(v[2]);
  return __builtin_sqrt(x * x + y * y + z * z);
}
