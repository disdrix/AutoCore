# Review A (reconstruction fidelity): `aa_0053e020` VehicleNet_SoftPoseBufferAlloc_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053e020` |
| **VA** | `0x0053e020` |
| **Canonical name** | `VehicleNet_SoftPoseBufferAlloc_Inferred` (was `FUN_0053e020`) |
| **Ghidra symbol** | `FUN_0053e020` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ machine) |
| **Counterpart** | `reviews/B_aa_0053e020_VehicleNet_SoftPoseBufferAlloc_Inferred.md` |
| **System** | `input-drive-control` / vehicle ghost soft-pose |
| **Dual status** | **Present** |
| **Verdict** | **accept** — trivial 0x40 alloc + identity-quat init sealed |

---

## 1. Purpose

Allocate and zero-initialize a **0x40-byte soft pose / dead-reckon buffer** used by network soft apply (`FUN_0053eec0`) and soft integrate (`FUN_0053eb90`). Identity quaternion has **w = 1** (`g_flOne` written over rot.w slot after zeroing).

**Not** a network apply, integrate, or physics write — pure factory.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x0053e020` |
| Raw / annotated / clean | `raw/aa_0053e020_*`, `reconstructed-exact/FUN_0053e020.cpp` |
| Parent verified | `physics/verified/fn_0053eec0_networkApply.md` §4 buffer layout |
| Consumers | `FUN_0053eec0`, `FUN_0053eb90`, `FUN_0053e0b0` |

**Not performed:** Launcher, runtime, bit-exact.

---

## 3. Authoritative body

```c
// no args; returns float*/void* buffer (decomp void but callers take return)
void* FUN_0053e020(void) {
  float *buf = operator_new(0x40);
  buf[0..3]  = 0;                    // +0x00 pos xyzw
  buf[4..6]  = 0; buf[7] = g_flOne;  // +0x10 rot; w=1 identity
  buf[8..11] = 0;                    // +0x20 linVel
  buf[12..15]= 0;                    // +0x30 angVel
  return buf;
}
```

Live decompile writes `puVar2[7] = 0` then `puVar2[7] = fVar1` (`g_flOne`) — sealed identity-w.

### Soft-buffer layout (consumer contract)

| Off | Field |
|----:|-------|
| `+0x00..0x0c` | position xyzw |
| `+0x10..0x1c` | rotation xyzw (init w=1) |
| `+0x20..0x2c` | linear velocity xyzw |
| `+0x30..0x3c` | angular velocity xyzw |

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| 0x40 `operator_new` | **High** |
| Zero all slots then rot.w=1 | **High** |
| Used as entity+0x28 soft buffer | **High** (callers) |
| Product/PDB name | Open (`_Inferred`) |

**Verdict:** **accept**
