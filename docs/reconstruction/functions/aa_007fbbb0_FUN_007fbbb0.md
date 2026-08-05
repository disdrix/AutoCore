# Function record: FUN_007fbbb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fbbb0` |
| **Canonical name** | `FUN_007fbbb0` |
| **Address** | `0x007fbbb0`–`0x007fbc6a` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` (Grab pre-helper / shared held clear) |
| **Completion status** | **Partial — dual A/B accept-with-gaps** (2026-07-29 wave8 OWN-ONLY) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

Human name: `Named_CalleeOf_Client_SendInventoryGrab_FromGrid_007fbbb0`  
Working description: **client-host held inventory object UI clear** (ESI method). Used before InventoryGrab pack/send; also other UI fan-in.

## Purpose

If `*(ESI+0x113c)` held object is non-null, `vtbl+0xd0()` is true, and `*(held+0x2b0)!=0`: detach via UI root `**(ESI+0xf40)` (`vtbl+0xb0`), release held (`vtbl+4(0)`), clear UI (`vtbl+0x1c8/0x3c0`), optionally copy fields `0x514→0x498` and `0x518→0x49c` when positive. **Not** a C2S packer.

## Signature (decompiler-derived)

```c
void FUN_007fbbb0(void)  /* ESI = client host* */
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_007fbbb0_FUN_007fbbb0.md`
- Annotated: `docs/reconstruction/raw/aa_007fbbb0_FUN_007fbbb0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_007fbbb0.cpp`
- Named clean: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_SendInventoryGrab_FromGrid_007fbbb0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_007fbbb0_FUN_007fbbb0.md`
- Dual B: `docs/reconstruction/reviews/B_aa_007fbbb0_FUN_007fbbb0.md`

## Callers / callees

**Callers (11 UNCONDITIONAL_CALL xrefs):**

| Site | Parent (DB) |
|---|---|
| `0x00860e66` | `Client_SendInventoryGrab_FromGrid` |
| `0x00862d99` | `Client_SendInventoryGrab_Hardpoint` |
| `0x007ff57b` | `FUN_007ff3d0` |
| `0x00802243` | `FUN_00802170` |
| `0x00861b61` | `FUN_00861680` |
| `0x009452ff` | `FUN_00944d50` |
| `0x008c3ccc` | `FUN_008c3ca0` |
| `0x009257cb` | *(unnamed in summary)* |
| `0x0083e5eb` | *(unnamed)* |
| `0x0083e6de` | *(unnamed)* |
| `0x008c2c07` | *(unnamed)* |

**Callees:** none named (all CALLIND).

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **Confirmed** (live ≡ raw) |
| ESI host + offsets | **High** |
| Grab pre-placement | **High** |
| Vtbl / field semantic names | **Tentative** |
| Runtime / bit-exact | Open |
