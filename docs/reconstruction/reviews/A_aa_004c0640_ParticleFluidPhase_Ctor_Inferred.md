# Review A (reconstruction fidelity): `aa_004c0640` ParticleFluidPhase_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c0640` |
| **VA** | `0x004c0640`–`0x004c0706` (**199 B**) |
| **Canonical name** | `ParticleFluidPhase_Ctor_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_004c0640` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-M) |
| **Counterpart** | `reviews/B_aa_004c0640_ParticleFluidPhase_Ctor_Inferred.md` |
| **System** | client / particle fluid phase |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full 199 B) + `analyze_function_complete` + callers; W32-O HostBase + W33-S Init peer |
| **Verdict** | **accept** |

---

## 1. Purpose

Derived constructor for the 0xC8 fluid-particle phase host:

1. SEH frame; `HostBase_DefaultCtor_Inferred(this)`.
2. Replace vtbl → `PTR_FUN_009cb62c`; `+0x80 = 1`.
3. `FUN_0096f530` @ `+0x84` and `+0x8c`.
4. Zero `+0x94/+0x98/+0x9c`; store parent @ `+0xa0`; copy `parent+0xe4e8` → `+0xa4`, `parent+0xe894` → `+0xa8`.
5. Zero `+0xac/+0xb0/+0xb4` and `+0xbc/+0xc0/+0xc4`.
6. `DAT_00b03790 = this`; `+0x78 = 0`; return this.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004c0640_FUN_004c0640.md` (+ W34-M append) |
| Annotated | `docs/reconstruction/raw/aa_004c0640_FUN_004c0640.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ParticleFluidPhase_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c0640.cpp` |
| Function record | `docs/reconstruction/functions/aa_004c0640_FUN_004c0640.md` |
| Named record | `docs/reconstruction/functions/aa_004c0640_ParticleFluidPhase_Ctor_Inferred.md` |
| Live | decompile ≡ raw CF; full 199 B hex; `MOV ESI,ECX`; `RET 4` |
| Context | W31-P InitPhases sole caller; W33-S Init method; W32-O HostBase |

---

## 3. Signature (sealed)

```c
// ECX=this; stack parent*; returns this; RET 0x4
void* __thiscall ParticleFluidPhase_Ctor_Inferred(void* self /*ECX*/, void* parent);
```

| Slot | Source | Conf |
|---|---|---|
| this | **ECX** (`MOV ESI,ECX`) | **High** |
| parent | Stack[+4] | **High** |
| return | EAX = this | **High** |
| cleanup | `RET 0x4` after SEH `ADD ESP,0x10` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
HostBase_DefaultCtor(this)
vtbl = PTR_FUN_009cb62c; [this+0x80]=1
FUN_0096f530(this+0x84); FUN_0096f530(this+0x8c)
zeros + parent wiring + DAT_00b03790 + [this+0x78]=0
return this
```

| Stage | Match | Conf |
|---|---|---|
| Linear ctor CF | **Yes** | **High** |
| Base → `007560d0` | **Yes** (rel32) | **High** |
| Vtbl / offsets | **Yes** (bytes) | **High** |
| Sole caller InitPhases | **Yes** (xref) | **High** |

---

## 5. Verdict

Full body + layout + ABI sealed; product demangle residual only → **accept**.
