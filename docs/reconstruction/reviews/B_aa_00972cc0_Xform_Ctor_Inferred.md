# Review B (skeptical / adversarial): `aa_00972cc0` Xform_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00972cc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-D) |
| **Counterpart** | `reviews/A_aa_00972cc0_Xform_Ctor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `void` return (decompiler) | **Falsified** — `MOV EAX,ECX` at entry; EAX not clobbered before `RET` |
| 2 | Stack `this` / stdcall | **Falsified** — ECX this; no stack args; plain `RET` |
| 3 | Single mat4 only | **Falsified** — two full 16-dword copies to `+0x00` and `+0x40` |
| 4 | Size smaller than 0xC0 | **Falsified** — last stores at `+0xB4/+0xB8/+0xBC`; alloc sites use `0xC0` |
| 5 | Non-leaf (calls helpers) | **Falsified** — no `E8`/`FF` call; pure stores + `REP MOVSD` |
| 6 | `DAT_00afdf70` not identity | **Falsified** — memory is diag(1,1,1,1) |
| 7 | Product name `gfxView` exclusive | **Overstated** — many non-view callers; scaffold callee-of rejected |
| 8 | Scale starts at `+0xa0` only | **Falsified** — `FUN_0044b440` treats `+0x9c/+0xa0/+0xa4` as scale xyz (init all 1) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX this + EAX return this | **High** | Wrong ensure/ctor ABI |
| Identity dual mat4 | **High** | Bad default orientation |
| TRS defaults + dirty 0 | **High** | Stale dirty / wrong scale |
| Block size 0xC0 | **High** | Alloc mismatch |
| Product English | **Inferred** | Naming only |
| `+0xa8` triple role | **Tentative** | Misnamed field only |
| Runtime | **Open** | Residual |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  copy identity → [0], [0x40]
  (0,0,0,1) @ 0x80; zeros @ 0x90; ones @ 0x9c..0xb0
  zero b4 / byte b8 / bc
  return

bytes (171 B):
  MOVSS XMM0,[g_flOne]; XORPS XMM1,XMM1; MOV EAX,ECX
  REP MOVSD ×16 from DAT_00afdf70 → EAX
  LEA EDI,[EAX+0x40]; REP MOVSD ×16 again
  MOVSS chain for 0x80..0xB0
  XOR ECX,ECX; store b4/b8/bc; RET
```

`read_memory(DAT_00afdf70)` = identity floats; `g_flOne` = `1.0f`. Live ≡ scaffold CF.

Consumer polarity: GfxView ctor allocates 0xC0 aligned then calls this; EnvironmentReflect stamps `+0x90` subobject; scale helper `FUN_0044b440` mutates `+0x9c` family — consistent with init layout.

---

## 4. Surviving contract for AutoCore

```
// Xform block default ctor (leaf):
//   ECX = XformBlock* (0xC0), returns this in EAX
//   mat4[0] = mat4[1] = identity (DAT_00afdf70)
//   quat = (0,0,0,1); pos = (0,0,0); scale = (1,1,1);
//   extra triple (+0xa8) = (1,1,1);
//   version=0; nonuniform=0; dirty=0
// Do not trust decompiler void; do not invent stack args.
// Pair with _aligned_malloc(0xC0, 0x10) ensure sites.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/constants/size; product field English residual does not block seal → **accept-with-gaps**.
