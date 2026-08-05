# Review B (skeptical / adversarial): `aa_00972fa0` Xform_TransformLocalPointToWorld_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00972fa0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual — live Ghidra) |
| **Counterpart** | `reviews/A_aa_00972fa0_Xform_TransformLocalPointToWorld_Inferred.md` |
| **System** | `gfx-math` (shared basis transform) |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on reg CC + dirty gate + point (w=1) out triple; **reject** decompiler-only signature, “direction transform”, “void no return”, gfxDevice-exclusive ownership, and sealed product symbol |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Signature is truly `void FUN_00972fa0(void)` with no args | **Falsified** — `RET 4`, stack loads local point*, EDI out, EAX basis; `MOV EAX,EDI` return |
| 2 | `unaff_EDI` / `in_EAX` are decompiler noise without meaning | **Falsified as “noise”** — they **are** the calling convention; decompiler failed to promote them to formals |
| 3 | This is a direction / normal transform | **Falsified** — routes through `0076f6e0` which hardcodes **w=1.0** (`0x3f800000`); direction sibling is `009729d0` (w=0) |
| 4 | Dirty rebuild is optional / dead | **Falsified** — every entry tests `[EAX+0xbc]&1`; unproject parent also tests same bit on other arms |
| 5 | Matrix is not at basis base | **Weakened if absolute elsewhere** — `0076f240` multiplies `ESI[0..0xf]`; ESI set from basis before call → **High** that live matrix is at `basis+0` |
| 6 | Function mutates the basis always | **Falsified if absolute** — only mutates when dirty (via `00972e50`); clean path is pure transform+store out |
| 7 | Scaffold name means only gfxDeviceVB owns it | **Falsified as exclusive** — 24 xrefs: unproject, DCT path, multiple gfx helpers, physics site `0044b836` |
| 8 | Same as `FUN_009729d0` | **Falsified** — different kernel (w=1 vs w=0), dirty gate present vs absent, out via EDI vs in-place |
| 9 | Ready for bit-exact port of full 4×4 without callee duals | **Fail / Open** — OWN seals glue; `0076f240` has branched mat×vec paths; rebuild `0076f970` not dualed |
| 10 | Product C++ name is known | **Hold inferred** — no string in body |
| 11 | Stack arg is an integer handle | **Falsified** — call sites push `LEA` of float triples; kernel loads three `MOVSS` from `[EAX]` |
| 12 | Returns void so callers ignore EAX | **Falsified** — unproject/DCT sites copy `*(EAX)`, `*(EAX+4)`, `*(EAX+8)` immediately after CALL |

---

## 2. Decisive dataflow (raw CF + live assembly)

```
// Entry regs:
//   EAX = basis*
//   EDI = float out[3]
//   [ret+4] = float* local

if (*(u8*)(basis + 0xbc) & 1):
    FUN_00972e50(basis)          // ECX=basis; rebuild; clear dirty bit0

ESI = basis
EAX = local*
EBX = &tmp[3]
FUN_0076f6e0()                   // point: w=1; M@ESI; writes EBX

out[0..2] = tmp[0..2]
return out                       // EAX = EDI
```

Live decompile 2026-07-29 matches 2026-07-23 raw **control skeleton**; assembly **adds** the register/stack contract the decompiler omitted.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX basis / EDI out / stack local* / RET 4 | **Confirmed** | Wrong CC → corrupt transforms / crash |
| Dirty `+0xbc` bit0 → rebuild | **Confirmed** | Stale matrix if skipped when dirty |
| Point (w=1) not direction | **High** | Translate component dropped or extra |
| Out is world-space point (parent use) | **High** | Unproject uses result as ray origin |
| Matrix storage at basis+0 | **High** | Misaligned mat mul |
| Optional homogeneous divide path | **High (callee body)** | Rare projective bases wrong if skipped |
| Product method name | **Inferred only** | Naming debt |
| Rebuild source fields (`+0x80/+0x90/+0x9c`) | **Medium (callee)** | Wrong if porting dirty path without dual |
| Runtime golden | **Open** | Residual parity |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| Dirty at `+0xbc` | Guess? | **No** — `TEST byte [EAX+0xbc],1` first insn after frame |
| `RET 4` | cdecl? | **No** — callee pops 4 |
| w=1 vs w=0 | Same as dir? | **No** — `0076f6e0` vs `009729d0` |
| EDI is “unaff” junk | Unused? | **No** — three `MOVSS` stores + return |
| Matrix at +0x20 (position triple) | Mul from +0x20? | **No** for this mul — mode-1 unproject **reads** `+0x20` as position copy; mat mul uses ESI base |
| Always divides by w | Always? | **No** — `0076f6e0` early-outs to raw xyz when \|w−1\| small |
| Only 1 caller | Unique? | **No** — 24 xrefs |
| Drive-axis side effect | Hidden? | **None** in OWN body |

---

## 5. Surviving contract for AutoCore

```
// Register-rich MSVC helper (not pure thiscall/cdecl):
//   EAX = BasisObject*   // mat4 @ +0; flags @ +0xbc
//   EDI = float* outWorldXYZ
//   stack: const float* localXYZ
//   returns float* outWorldXYZ  (same as EDI)

Xform_TransformLocalPointToWorld(basis, out, local):
  if basis.flags & DIRTY_MATRIX:          // bit0 of +0xbc
      RebuildBasisMatrix(basis)           // FUN_00972e50
  tmp = MulPoint_Mat4(basis.mat4, local)  // w=1 path FUN_0076f6e0 → FUN_0076f240
  out.xyz = tmp.xyz
  return out

// NOT FUN_009729d0 (direction / w=0).
// NOT a void leaf — callers consume EAX as out*.
// Dirty rebuild is OWN's responsibility when bit0 set.
```

Port must preserve: register CC, dirty gate before mul, **point** (w=1) kernel, three-float out, `RET 4`.

---

## 6. Falsification notes on over-claims

### 6.1 Trusting the decompiler signature

Scaffold clean/`void FUN_00972fa0(void)` is a **capture artifact**. Ports that treat EDI/EAX as unconstrained will fail every call site. Prefer assembly contract in dual A §5.

### 6.2 Collapsing point and direction helpers

Parent unproject dual already labeled `FUN_00972fa0` = transform **point** and `FUN_009729d0` = transform **direction**. This dual **seals** that split via w=1 vs w=0 kernels. Do not merge into one “TransformVector” without branching on w.

### 6.3 “Matrix always fresh”

Dirty bit means matrix **may** be stale. Skipping `00972e50` when bit0 is set yields wrong world points after basis edits (camera/node moves). Clean path does not call rebuild — do not force rebuild every time either.

### 6.4 gfxDevice-only ownership

Human scaffold `Named_CalleeOf_Named_gfxDeviceVB_00972fa0` is a **parent-seed alias**. High-traffic consumer for reconstruction is camera unproject / DCT look ray, not exclusively VB upload.

---

## 7. Open attacks (remain)

1. Exact product type name of the basis object (scene node vs camera vs generic xform).
2. Whether `+0xbc` bits beyond bit0 have other semantics in OWN (OWN only tests bit0).
3. Full numerical dual of `FUN_0076f240` branch table (affine fast-path vs full projective).
4. `FUN_00972e50` argument mapping into `FUN_0076f970` (decompiler of rebuild is register-messy — separate OWN dual).

**Verdict:** **accept-with-gaps** — adversarial pass confirms assembly CC and point-transform role; rejects void/decompiler-only and direction-collapse overclaims. Rebuild + mat4 bit-exact remain residual.
