# Review A (reconstruction fidelity): `aa_0051a0e0` MedalDef_LookupById

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051a0e0` |
| **VA** | `0x0051a0e0` |
| **Canonical name** | `FUN_0051a0e0` (proposed: `MedalDef_LookupById`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0051a0e0_MedalDef_LookupById.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** (table English **medal** Probable via toast path; lazy-load body open) |

---

## 1. Purpose

Global **medal definition lookup by integer id**:

1. If `(int)id < 0` → null.
2. If table count `DAT_00b042ec < 1`: call lazy loader `FUN_00519660()`; if still `< 1` → null.
3. Else `CNDHash_LookupByKey(&DAT_00b042e0, id)` → def pointer or null.

Used by medal award (`FUN_00530550`), CompleteObjective medal toast ("Earned the … Medal"), journal/UI peers.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0051a0e0_FUN_0051a0e0.md` |
| Annotated / clean / function record | scaffold set under same id |
| Live listing | `disassemble_function` `0x0051a0e0` |
| Call sites | CompleteObjective toast `0x005344ee`; AwardMedal `0x00530559`/`0x0053057d` |
| Parent residual | `reviews/a_00533f90.md` |

---

## 3. Body (listing)

```text
0051a0e0  PUSH ESI
0051a0e1  MOV ESI, [ESP+8]           ; id
0051a0e5  TEST ESI / JL → null
0051a0e9  CMP [DAT_00b042ec], 0
0051a0f0  JG ready
0051a0f2  CALL FUN_00519660          ; lazy ensure
0051a0f7  CMP [DAT_00b042ec], 0
0051a0fe  JLE → null
0051a100  PUSH ESI
0051a101  MOV ECX, 0x00b042e0
0051a106  CALL CNDHash_LookupByKey
0051a10c  RET                        ; cdecl 1 arg (caller ADD ESP,4)
```

Live decompile ≡ raw.

---

## 4. ABI / globals

```c
void* /* MedalDef* */ __cdecl MedalDef_LookupById(uint32_t id);
// negative (signed) id → null; bare RET; caller cleans 4
```

| Symbol | Role | Conf |
|---|---|---|
| `DAT_00b042e0` | Medal hash table object | **High** CF |
| `DAT_00b042ec` | Table occupancy / ready count | **High** CF; exact meaning open |
| `FUN_00519660` | Lazy load/init medals | **High** call; body not dualed here |
| `CNDHash_LookupByKey` | Standard hash get | **High** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Negative id null | **High** | signed test |
| Lazy load gate | **High** | |
| Hash lookup return | **High** | |
| Def is **medal** | **Probable** | toast "Medal" + award path; PDB open |
| `FUN_00519660` full semantics | **Open** | missing dual this batch |

---

## 6. Surviving contract

```
MedalDef* Lookup(id):
  if (int)id < 0: return null
  ensure table loaded (count DAT_00b042ec > 0 via FUN_00519660)
  return CNDHash_LookupByKey(&DAT_00b042e0, id)
```
