# Review A (reconstruction fidelity): `aa_00970e50` AssPreloader_RetireStaleNeverLoaded_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00970e50` |
| **VA** | `0x00970e50`–`0x00970fb8` (**360 B**) |
| **Canonical name** | `AssPreloader_RetireStaleNeverLoaded_Inferred` |
| **Ghidra name** | `FUN_00970e50` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-O) |
| **Counterpart** | `reviews/B_aa_00970e50_AssPreloader_RetireStaleNeverLoaded_Inferred.md` |
| **System** | assPreloader / asset preload pipeline |
| **Evidence pass** | Live Ghidra `batch_decompile` / `analyze_function_complete` + `read_memory` (full 360 B + product strings) + sole caller |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Age-scan AssPreloader tracked map; retire never-loaded entries older than `maxAge`, release owned objects, push to ring `+0xAC`, erase nodes; always log retire count.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00970e50_FUN_00970e50.md` (+ W33-O hex append) |
| Annotated | `docs/reconstruction/raw/aa_00970e50_FUN_00970e50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPreloader_RetireStaleNeverLoaded_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00970e50.cpp` |
| Function record | `docs/reconstruction/functions/aa_00970e50_FUN_00970e50.md` |
| Named record | `docs/reconstruction/functions/aa_00970e50_AssPreloader_RetireStaleNeverLoaded_Inferred.md` |
| Live | decompile CF + full body hex; `RET 8`; product strings @ `00a9ea4c` / `00a9ea24` |

---

## 3. Signature (sealed)

```c
// stack (AssPreloader* self, float maxAge); RET 8; void
void AssPreloader_RetireStaleNeverLoaded_Inferred(void* self, float maxAge);
```

| Slot | Source | Conf |
|---|---|---|
| self | Stack; `MOV EBP,[ESP+…]`; map via `EBP+0x14` | **High** |
| maxAge | Stack float; `COMISS` vs age | **High** |
| cleanup | **`RET 8`** (`C2 08 00`) | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
now = Timer_GetTimeSeconds
retired = 0
for node in map(self+0x10 / end self+0x14):
  if (now - node.stamp@+0x14) <= maxAge:
    iterator++
  else:
    optional vtbl[0](*(node+0x10), 1)
    assId from key@+0xC; log never-loaded (line 0x2A8)
    push locked PodU32U8 → self+0xAC
    iterator++; erase(self+0x10); retired++
log "Retired %d preload blocks..." (line 0x2B7)
```

| Stage | Match | Conf |
|---|---|---|
| RET 8 + two stack args | **Yes** | **High** |
| Age polarity `<= maxAge` keep | **Yes** | **High** |
| Product never-loaded + count logs | **Yes** | **High** |
| Ring +0xAC on retire | **Yes** | **High** |
| Caller maxAge 300.0f | **Yes** | **High** |

---

## 5. Gaps (explicit)

- Product/PDB method English (name **Inferred**).
- Exact map element type / key object beyond assId helper.
- Nested `FUN_00447350` / iterator dual residual.
- Runtime / bit-exact / differential.

---

## 6. Verdict

Fidelity pass seals ABI, CF, age polarity, product logs, map/ring offsets. Nested types + runtime → **accept-with-gaps**.
