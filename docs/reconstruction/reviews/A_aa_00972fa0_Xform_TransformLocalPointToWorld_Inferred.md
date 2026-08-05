# Review A (reconstruction fidelity): `aa_00972fa0` Xform_TransformLocalPointToWorld_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00972fa0` |
| **VA** | `0x00972fa0` |
| **Canonical name** | `FUN_00972fa0` |
| **Role name (inferred)** | `Xform_TransformLocalPointToWorld_Inferred` |
| **Prior scaffold names** | `Named_CalleeOf_Named_gfxDeviceVB_00972fa0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual — live Ghidra decompile + `disassemble_function` + `read_memory` constants on callees) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw CF; **register CC sealed from assembly**, not decompiler phantoms) |
| **Counterpart** | `reviews/B_aa_00972fa0_Xform_TransformLocalPointToWorld_Inferred.md` |
| **System** | `gfx-math` / shared basis transform (camera unproject, DCT, gfxDevice, pick) |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** — CC + dirty gate + point-transform (w=1) + out triple sealed; product symbol + full matrix layout open |

---

## 1. Purpose

**World-transform helper**: maps a **local-space point** (3 floats) through a **basis / scene-node transform object** into a **world-space point** written to a caller-supplied `float[3]`.

1. If basis dirty flag `*(basis + 0xbc) & 1` is set → `FUN_00972e50(basis)` rebuilds the cached 4×4 (and clears bit 0 of `+0xbc`).
2. Homogeneous **point** transform via `FUN_0076f6e0`: load xyz from stack arg, set **w = 1.0**, multiply by 4×4 at basis base (`FUN_0076f240` with ESI = basis), optional perspective divide when |w−1| is large.
3. Copy result xyz → `*out` (`EDI`); return `EAX = out`.

**Does not** transform directions (that is sibling `FUN_009729d0`, which forces **w = 0** and has no dirty gate). Pure geometric out-param helper — no entity/drive side effects.

**Calling convention (assembly-sealed, not decompiler `void`):**

| Register / stack | Role |
|---|---|
| **EAX** | `basis*` — object with 4×4 matrix at `+0` and dirty flags at `+0xbc` |
| **EDI** | `float* outWorld` — destination xyz |
| **`[esp+4]`** (after call) | `const float* localPoint` — source xyz |
| **Return EAX** | same as `EDI` (`outWorld`) |
| **Stack cleanup** | `RET 4` → **stdcall-1** stack arg |

Decompiler shows `in_EAX` / `unaff_EDI` / no formals — **phantoms only**; trust disasm.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00972fa0_FUN_00972fa0.md` |
| Annotated | `docs/reconstruction/raw/aa_00972fa0_FUN_00972fa0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00972fa0.cpp` |
| Prior scaffold clean | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_gfxDeviceVB_00972fa0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00972fa0_FUN_00972fa0.md` |
| Parent consumer (roles) | `GfxView_UnprojectScreenToWorldRay_Inferred` `0x0075c340` (near-plane world point) |
| Sibling dir xform | `FUN_009729d0` `0x009729d0` (w=0; no dirty gate in body) |
| Dirty rebuild | `FUN_00972e50` `0x00972e50` (role only — not dualed this pass) |
| Point kernel | `FUN_0076f6e0` `0x0076f6e0` (role only) |
| Mat4×vec4 | `FUN_0076f240` `0x0076f240` (role only) |
| Scratch | `docs/reconstruction/tmp/a_00972fa0.md` |

**This pass (live):** Ghidra `decompile_function` @ `0x00972fa0`; `disassemble_function` (authoritative CC); `batch_decompile` callees `0x00972e50`, `0x0076f6e0`, `0x0076f240` (**roles only**); `analyze_function_complete` (24 xrefs / 21 callers); `get_assembly_context` at `0x0075c3e6`, `0x00920bfd`, `0x0074c0e2`, `0x0044b836`; `read_memory` constants used by point kernel (`0x00a0f2a0`=1.0, `0x00a240ec`≈1e−6, `0x00aaa640`≈−1e−6, `0x00aaa5f8` double 1.0). **Not performed:** Launcher, runtime golden, bit-exact binary diff, full dual of callees.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body CF ≡ 2026-07-23 raw ≡ live decompile | **High** | Same if/call/store skeleton; raw omitted reg CC |
| EAX = basis object | **Confirmed** | `TEST byte [EAX+0xbc],1`; `MOV ESI,EAX` |
| EDI = out float[3] | **Confirmed** | `MOVSS [EDI]…[EDI+8]`; `MOV EAX,EDI` |
| Stack arg = `const float* localPoint` | **Confirmed** | `MOV EAX,[ESP+0x24]` after frame; `RET 4` |
| Dirty gate `basis+0xbc & 1` → `FUN_00972e50` | **Confirmed** | TEST/JZ; `MOV ECX,EAX; CALL 972e50` |
| Point transform (w=1) not direction | **High** | Via `0076f6e0` which stores `0x3f800000` as w before `0076f240` |
| Sibling `009729d0` is direction (w=0) | **High** | Sibling raw: `local_14 = 0` then same mat mul |
| Matrix at basis `+0` (16 floats) | **High** | `0076f240` uses `unaff_ESI[0..0xf]`; ESI left = basis |
| Optional /w when \|w−1\| large | **High CF (callee)** | In `0076f6e0`; constants re-read |
| Return pointer = out | **Confirmed** | `MOV EAX,EDI` before epilogue |
| Product C++ method name | **Inferred** | No body string; role from CF + unproject parent |
| Full 4×4 element layout / row-major seal | **Medium** | Formula in `0076f240` is full mat×vec; row/col product names open |
| Exact rebuild math of `00972e50` / `0076f970` | **Open (callee)** | OWN only uses dirty gate; rebuild dual separate |
| Runtime golden (local→world) | **Open** | Deferred |

---

## 4. Control flow: clean ≡ raw ≡ live decompile

| Stage | Match |
|---|---|
| Test dirty bit at `basis+0xbc` | **Yes** |
| Conditional rebuild `FUN_00972e50` | **Yes** |
| Call point kernel `FUN_0076f6e0` | **Yes** |
| Store 3 floats to out | **Yes** |
| Return out pointer | **Yes** (assembly; decompiler drops return type) |
| No invent drive / entity side effects | **Yes** |

### 4.1 Recovered CF (assembly-aligned)

```c
// Custom register + stdcall-1:
//   EAX = basis*  (4x4 at +0, dirty flags at +0xbc)
//   EDI = float outWorld[3]
//   stack arg0 = const float localPoint[3]
//   returns EAX = outWorld
float *FUN_00972fa0(void /* regs + 1 stack */)
{
    float *basis = (float *)/*EAX*/;
    float *out   = (float *)/*EDI*/;
    float *local = *(float **)(/* stack arg */);
    float tmp[3];

    if ((*(unsigned char *)((char *)basis + 0xbc) & 1) != 0) {
        FUN_00972e50(basis);   // ECX=basis; rebuild cached matrix, clear dirty bit0
    }
    // ESI remains basis; EAX=local; EBX=&tmp
    FUN_0076f6e0(/* point xform: w=1, M=basis, in=local, out=tmp */);
    out[0] = tmp[0];
    out[1] = tmp[1];
    out[2] = tmp[2];
    return out;
}
```

### 4.2 Point kernel role (`FUN_0076f6e0` — not dualed)

```
in  = *localPoint as xyz; w = 1.0f
out4 = basis_mat4 × in4          // FUN_0076f240 (ESI=matrix base)
if |out4.w - 1| large enough (eps @ 0x00a240ec ≈ 1e-6):
  optionally out.xyz /= out4.w
else:
  out.xyz = out4.xyz
```

Constants (`read_memory` this pass):

| VA | Bytes | Value |
|---|---|---|
| `0x00a0f2a0` | `00 00 80 3f` | **1.0f** (`g_flOne`) |
| `0x00a240ec` | `bd 37 86 35` | **≈ 1e−6** |
| `0x00aaa640` | `bd 37 86 b5` | **≈ −1e−6** |
| `0x00aaa5f8` | `00 00 00 00 00 00 f0 3f` | **1.0** (double) |

---

## 5. Assembly contract (`disassemble_function` @ `0x00972fa0`)

```
00972fa0  SUB  ESP,0x18
00972fa3  TEST byte ptr [EAX+0xbc],0x1
00972faa  JZ   skip_rebuild
00972fac  MOV  ECX,EAX
00972fae  CALL FUN_00972e50
skip_rebuild:
00972fb3  PUSH EBX
00972fb4  PUSH ESI
00972fb5  MOV  ESI,EAX                 ; ESI = basis (matrix for 76f240)
00972fb7  MOV  EAX,dword ptr [ESP+0x24]; localPoint*
00972fbb  LEA  EBX,[ESP+0x14]          ; tmp out for 76f6e0
00972fbf  CALL FUN_0076f6e0
00972fc4  … MOVSS chain copy tmp → stack shadows …
00972ffe  MOVSS dword ptr [EDI],XMM0   ; out.x
00973010  MOVSS dword ptr [EDI+4],XMM0 ; out.y
0097301c  MOVSS dword ptr [EDI+8],XMM0 ; out.z
00973021  MOV  EAX,EDI                 ; return out*
00973023  POP  EBX
00973024  ADD  ESP,0x18
00973027  RET  4
```

---

## 6. Call-site pattern (OWN does not own caller CF)

| Site | Caller (sample) | Setup |
|---|---|---|
| `0x0075c3e6` | `FUN_0075c340` unproject | `EAX = *(gfxView+8)` basis; `EDI` = stack world-near; push local near-plane point |
| `0x00920bfd` | `FUN_00920a50` (DCT-related) | `LEA EDI, stack`; push local; after call loads `[EAX]+0/4/8` |
| `0x0074c0e2` | gfx helper | `MOV EAX,ESI` basis; `LEA EDI,stack`; push point |
| `0x0044b836` | physics/gfx | `MOV EAX,EBP` basis; `LEA EDI,stack`; push `ESI+0x20` local |

24 xrefs / 21 distinct callers (live complete analysis). Scaffold “gfxDeviceVB callee” is one parent seed only.

---

## 7. Twin relationship

| | Point (`00972fa0`) | Direction (`009729d0`) |
|---|---|---|
| Homogeneous w | **1.0** (via `0076f6e0`) | **0.0** (in body) |
| Dirty gate | **Yes** (`+0xbc & 1` → `00972e50`) | **No** (callers may pre-resolve) |
| Out | separate `EDI` buffer | often **in-place** on arg |
| Role | local **position** → world | local **direction** → world |

Unproject parent uses **both**: point for ray origin (`00972fa0`), dir path via normalize + `009729d0`.

---

## 8. Gaps

1. Retail symbol for this VA (no string; keep `FUN_00972fa0` / `_Inferred` role).
2. Full dual of `FUN_00972e50` / `FUN_0076f970` rebuild (quat/scale/pos at `+0x80/+0x90/+0x9c`).
3. Bit-exact mat4 memory order labels (row-vector vs column-vector product naming).
4. Runtime golden local→world samples.

**Verdict:** **accept-with-gaps** — sealed as the shared **local point → world point** basis helper with register CC + dirty refresh. Product name and rebuild matrix dual remain open.
