# Review A (reconstruction fidelity): `aa_005b3520` CVOGEnvironmentReflect_ResolveLightEffectSlots_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b3520` |
| **VA** | `0x005b3520`–`0x005b357a` (**91 B**) |
| **Canonical name** | `CVOGEnvironmentReflect_ResolveLightEffectSlots_Inferred` |
| **Ghidra name** | `FUN_005b3520` |
| **Review date** | `2026-08-04` (W37-F dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-F) |
| **Counterpart** | `reviews/B_aa_005b3520_CVOGEnvironmentReflect_ResolveLightEffectSlots_Inferred.md` |
| **System** | CVOGEnvironmentReflect light-effect slot resolve |
| **Evidence pass** | Live Ghidra decompile + `read_memory` (full 91 B) + `analyze_function_complete` + callers/callees + `analyze_dataflow` on hemi gate + ctor/enable context |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Once-only resolve of nested default-light effect cores into Reflect `+0x150`/`+0x154`, then aux-bind hemi core through `FUN_0074e310`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005b3520_FUN_005b3520.md` (+ W37-F append) |
| Annotated | `docs/reconstruction/raw/aa_005b3520_FUN_005b3520.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGEnvironmentReflect_ResolveLightEffectSlots_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005b3520.cpp` |
| Function | `docs/reconstruction/functions/aa_005b3520_*.md` |
| Live | decompile ≡ raw CF; full 91 B hex; 2 callers |
| Context | W33-T Enable; W32-R RebuildDefaultLights; Reflect ctor `0x005b35a0` |

---

## 3. Signature (sealed)

```c
void __thiscall CVOGEnvironmentReflect_ResolveLightEffectSlots_Inferred(
    CVOGEnvironmentReflect* this);
```

| Slot | Source | Conf |
|---|---|---|
| ECX `this` | Reflect enable/rebuild callers | **High** |
| No stack formals | bare `C3` | **High** |
| Void | no EAX set | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if (self+0x154 != 0) return
parent = *(self+0x15c)
host = *(parent+0xe894)
if (host+0x108 == 0) return
if (host+0x104 != 0) return
self+0x154 = *(*(host+0x108)+0x8c)
host = *(parent+0xe894)
res = *(*(host+0x104)+0x8c)
self+0x150 = res
FUN_0074e310(*(self+4), res)
```

| Stage | Match | Conf |
|---|---|---|
| Once-gate `+0x154` | **Yes** | **High** |
| Parent / `+0xe894` host | **Yes** | **High** |
| Dir/hemi offsets + `+0x8c` cores | **Yes** | **High** |
| Aux this-adjust + `FUN_0074e310` | **Yes** | **High** |
| Hemi-null enter gate | **Yes** (bytes) | **High** (product intent residual) |
| Host class Reflect | **Yes** (RTTI) | **High** |

---

## 5. Gaps (do not block structural seal)

1. Hemi-null gate vs hemi load — product residual (often no-op after full light rebuild).
2. Product English for effect-core objects.
3. Runtime / bit-exact / differential.

---

## 6. Verdict

Fidelity pass seals 91 B CF, thiscall ABI, slot map, two callers, single callee, Reflect naming from RTTI family. Residual hemi gate documented. **accept-with-gaps**.
