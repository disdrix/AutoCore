# Review A (reconstruction fidelity): `aa_004044e0` CombatFloater_FillRangeFromTemplate_0x38_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004044e0` |
| **VA** | `0x004044e0` |
| **Canonical name** | `CombatFloater_FillRangeFromTemplate_0x38_Inferred` |
| **Prior scaffold** | `FUN_004044e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004044e0_CombatFloater_FillRangeFromTemplate_0x38_Inferred.md` |
| **System** | `missions-progression` / combat floater UI (+ shared POD fill) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

---

## 1. Purpose

**Assign / fill range** of combat-floater (or same-layout) POD slots from **one template**:

```
while (cur != end) {
  next = cur + 0xE dwords;          // +0x38 bytes
  copy 14 dwords from *template into *cur
  cur = next;
}
```

Element size **0x38** (= `0xE * 4`). Source template pointer does **not** advance across elements — same blob stamped into every slot.

Callers:

| Caller | Role |
|---|---|
| `FUN_00403680` | Combat floater vector insert (in-place assign path) |
| `FUN_005e99d0` | other 0x38-POD consumer |
| `FUN_00690ee0` | other 0x38-POD consumer |

**Not** range-to-range relocate (`0x004044c0`); **not** count-based ConstructN wrapper (`0x00402ea0`).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x004044e0` |
| Callers | `get_function_callers` |
| Raw / clean | `aa_004044e0_*` |
| Sibling duals | PodCopy / ConstructN / InsertN |

**Not performed:** Launcher, runtime, ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Outer walk until `param_1 == param_2` | **Confirmed** | while |
| Inner copy **14 dwords** | **Confirmed** | `iVar2 = 0xe` |
| Advance **+0x38** per element | **Confirmed** | `param_1 + 0xe` dword ptrs |
| Template fixed (`param_3` reloaded each outer iter) | **Confirmed** | `puVar3 = param_3` each time |
| No callees / leaf | **Confirmed** | body only stores |
| Free function (not thiscall host) | **High** | no ECX host use in body |

---

## 4. Control flow: clean ≡ raw ≡ live

```c
void FillRangeFromTemplate(uint32_t *cur, uint32_t *end, uint32_t *tmpl) {
  while (cur != end) {
    uint32_t *next = cur + 0xE;
    uint32_t *s = tmpl, *d = cur;
    for (int i = 0xE; i != 0; --i) { *d++ = *s++; }
    cur = next;
  }
}
```

| Stage | Match |
|---|---|
| Empty range no-op | Yes |
| Full 0x38 dword stamp | Yes |
| No invent growth | Yes |

---

## 5. Gaps / open

1. Whether non-floater callers share true type identity or only size 0x38.
2. Product name.

**Verdict:** **accept**
