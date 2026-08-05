# Review B (skeptical / adversarial): `aa_00521900` Character_GetClassDisplayName_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00521900` |
| **VA** | `0x00521900` |
| **Canonical name** | `Character_GetClassDisplayName_Inferred` (**Inferred**) |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00521900_Character_GetClassDisplayName_Inferred.md` |
| **System** | missions-progression / character display |
| **Live tools** | Independent decompile + `read_memory` + callee/caller decompiles |
| **Verdict** | **accept-with-gaps** — accept thin wrapper CF; reject 3-arg lookup, void return, race-only naming |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | `FUN_0051f940` takes 3 args (`…, 0xffffffff`) | **Falsified** — `add esp,8` after call; `-1` is `FUN_007a6de0` length |
| 2 | Args are (race, class) not (class, race) | **Falsified** — push class (edx from +0x531) then race (ecx from +0x532); callee switches on first param as class families |
| 3 | `void` return | **Falsified** — consumers use as `char*` |
| 4 | Self-contained string table in this function | **Falsified** — only calls lookup leaf; no embedded class strings here |
| 5 | Same as race helper (only +0x532) | **Falsified** — reads **both** +0x531 and +0x532 |
| 6 | Scaffold UpdateMissionJournal name is product | **Rejected** |
| 7 | Class table dual-sealed by owning this VA alone | **Open/unsafe** — table lives in unowned `0x0051f940` |
| 8 | Durable heap return | **Falsified** — TLS ring via `007a6de0` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Wrapper CF / offsets | **High** | Wrong class/race fields |
| 2-arg cdecl to 0051f940 | **High** | Stack imbalance / wrong names |
| char\* ring return | **High** | Lifetime bugs |
| Class English content | **Medium** (callee decompile only) | Mislabel class in journal |
| Product method English | **None** | Overclaim |

---

## 3. Decompiler pitfalls (must survive port)

1. Strip the phantom third arg to `FUN_0051f940`.
2. Keep argument order **(classId, raceId)**.
3. Port as thin wrapper; do not inline the class table without sealing `0x0051f940`.
4. Do not free return pointer.

---

## 4. What is safe to claim

| Safe | Unsafe |
|---|---|
| Thin thiscall wrapper over class×race lookup | Full dual seal of class name table without dualing 0051f940 |
| blob+0x531 class / +0x532 race | Class id meanings without table |
| Used for `[$class]` + UI formatters | PDB method English |

---

## 5. CF challenge of Review A

- Nested path + dual byte loads: **agree Confirmed**
- cdecl 2-arg + ring path: **agree Confirmed**
- Class table as supporting (unowned) evidence: **agree** — must not overclaim dual ownership
- accept-with-gaps: **agree**

**Verdict:** **accept-with-gaps**
