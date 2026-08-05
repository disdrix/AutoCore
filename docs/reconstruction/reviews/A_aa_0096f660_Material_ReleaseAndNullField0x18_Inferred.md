# Review A (reconstruction fidelity): `aa_0096f660` Material_ReleaseAndNullField0x18_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096f660` |
| **VA** | `0x0096f660`–`0x0096f681` |
| **Canonical name** | `Material_ReleaseAndNullField0x18_Inferred` |
| **Ghidra name** | `FUN_0096f660` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W26-M) |
| **Counterpart** | `reviews/B_aa_0096f660_Material_ReleaseAndNullField0x18_Inferred.md` |
| **System** | gfx / material resource |
| **Evidence pass** | Live Ghidra `decompile_function` + full-body `read_memory` + callers |
| **Verdict** | **accept** |

---

## 1. Purpose

Near-leaf **resource release** helper:

1. `obj = *holder` (ECX); if null return.
2. `res = *(obj + 0x18)`; if non-null: `--*(res + 4)`; if zero → `call [(*res)+8]`.
3. Always `*(obj + 0x18) = 0` when obj non-null.

Used immediately after material parameter writes (`MatAmbient` / `MatDiffuse` / `MatEmissive` via `FUN_009700f0`) in paint paths.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0096f660_FUN_0096f660.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_0096f660_FUN_0096f660.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Material_ReleaseAndNullField0x18_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0096f660.cpp` |
| Function | `docs/reconstruction/functions/aa_0096f660_FUN_0096f660.md` |
| Named | `docs/reconstruction/functions/aa_0096f660_Material_ReleaseAndNullField0x18_Inferred.md` |
| Live | decompile ≡ raw; **34 B** body hex exact |
| Callers | `FUN_0051aed0`, `FUN_005dbca0` |

---

## 3. Signature (sealed)

```c
// __fastcall; ECX holder; void; plain RET
void Material_ReleaseAndNullField0x18_Inferred(int* holder);
```

| Formal | Source | Conf |
|---|---|---|
| holder | ECX | **High** |
| return | void (`5E C3`) | **High** |
| stack args | none | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
ESI = *ECX
if ESI == 0: ret
ECX = [ESI+0x18]
if ECX != 0:
  [ECX+4]--
  if zero: call [[ECX]+8]
[ESI+0x18] = 0
ret
```

| Stage | Match | Conf |
|---|---|---|
| Null holder object early-out | **Yes** | **High** |
| Field `+0x18` resource load | **Yes** | **High** |
| Refcount at `+4` decrement | **Yes** | **High** |
| vtbl[+8] only on zero | **Yes** | **High** |
| Always null slot | **Yes** | **High** |
| No direct FUN_* callees | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body (**34 B**):
```
568b3185f674198b4e1885c9740b834104ff75058b01ff5008c74618000000005ec3
```

Pad `CC` from `0x0096f682`.

---

## 6. Gaps

- Product English for resource type / vtbl[+8] (`Release` vs custom free).
- Whether `FUN_009700f0` allocates the slot this clears (sibling, not OWN).
- Runtime — open.

---

## 7. Verdict

CF, ABI, offsets, and exclusive body hex are sealed. Naming is evidence-backed inference from role + Mat* callers → **accept**.
