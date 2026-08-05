# Review B (skeptical / adversarial): `aa_00933370` ObjectList_ExportTfidsToMap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00933370` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00933370_ObjectList_ExportTfidsToMap_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Filters by distance / type | No distance; inserts all non-null payloads | **Falsified** as filtered |
| 2 | Persists map on host | Local stack map + temporary list; delete at end | **Falsified** as host-owned persist |
| 3 | Decompiler noreturn means crash always | SEH + list free; warning is Ghidra artifact on `operator_delete` | **Noise** — still teardown |
| 4 | No ECX this | Call sites `mov ecx` | **Falsified** |
| 5 | Reads TFID from wrong offsets | Body copies `+0x160/+0x164` explicitly | **Sealed** |
| 6 | Only one caller | 3 xrefs in VOG client paths | **Falsified** |

---

## 2. Confidence table

| Area | Confidence | Risk if wrong |
|---|---|---|
| Walk all list payloads | **High** | Miss objects |
| TFID + cbid pack | **High** | Bad map keys |
| Temporary list from `vtbl+0x2b0` | **High** | Wrong source |
| Map insert `FUN_00406040` | **High** (addr) / **Probable** (type) | |
| Host field map layout | **Open** | Parent only |
| Runtime | **Open** | |

---

## 3. Surviving contract

```c
// thiscall-ish: ECX = list host with vtbl+0x2b0 enumerator
void ObjectList_ExportTfidsToMap(ObjectListHost* host /*ECX*/);
```

- Side effect: fills a **local** map via `FUN_00406040` during the walk (callers must consume before return — verify parent if map is out-param on stack; body as decompiled uses stack locals only).
- Note: if parent needs the map after return, parent must own storage — dual accepts decompiler-local view; parent xrefs show immediate follow-up uses in same frame.

---

## 4. Parent-map residual (adversarial note)

Decompiler shows map/list as **locals**. Parents call then continue with other stack slots — **gap**: whether `FUN_00406040` writes into a parent-visible structure via hidden pointer is not fully sealed without full parent decompile. CF of **walk + pack + insert callee** remains High.

---

## 5. Verdict

**accept-with-gaps** — enumeration sealed; post-return map ownership open at parent layer.
