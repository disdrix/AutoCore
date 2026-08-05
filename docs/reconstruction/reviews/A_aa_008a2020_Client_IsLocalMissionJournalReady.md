# Review A (reconstruction fidelity): `aa_008a2020` Client_IsLocalMissionJournalReady

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a2020` |
| **VA** | `0x008a2020`–`0x008a2037` |
| **Canonical name (proposed)** | `Client_IsLocalMissionJournalReady` |
| **Ghidra name** | `FUN_008a2020` |
| **Prior aliases** | `Named_CalleeOf_Mission_Client_BuildMissionDetailPanel_008a2020` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A) |
| **Counterpart** | `reviews/B_aa_008a2020_Client_IsLocalMissionJournalReady.md` |
| **Callee (sealed)** | `aa_0052b3b0` / `CVOGCharacter_IsMissionJournalReady` |
| **System tag** | `missions-progression` |
| **Agent** | W21-F OWN-ONLY |
| **Verdict** | **accept** on ABI / null gate / forward; **accept-with-gaps** on product English of wrapper + panel owner |

**Tools:** Ghidra `decompile_function` + `read_memory` (body + call site) + `get_xrefs_to` + `get_function_by_address`. No `disassemble_bytes`. No Launcher. No parent ledger edits.

---

## 1. Purpose

Client **null-safe journal-ready probe** for the local character:

```
bool Client_IsLocalMissionJournalReady(mission):
  char = DAT_00d1b6d8
  if char == null: return false
  return CVOGCharacter_IsMissionJournalReady(char, mission)   // 0x0052b3b0
```

Does **not** re-implement last-objective / active-hash / mode-0 logic — that lives entirely in the callee.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live Ghidra decompile | `FUN_008a2020` @ `0x008a2020` (≡ raw CF) |
| Image bytes | `read_memory` `0x008a2020`–`0x008a2037` |
| Call site | `read_memory` `0x008a3840`+; decompile `FUN_008a3510` |
| Xrefs | single call from `0x008a384b` |
| Raw | `docs/reconstruction/raw/aa_008a2020_FUN_008a2020.md` |
| Annotated | `docs/reconstruction/raw/aa_008a2020_FUN_008a2020.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_IsLocalMissionJournalReady.cpp` |
| Function record | `docs/reconstruction/functions/aa_008a2020_Client_IsLocalMissionJournalReady.md` |
| Callee dual | `A/B_aa_0052b3b0_CVOGCharacter_IsMissionJournalReady.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__cdecl`, 1 stack arg, bool AL | **High** | body `ret`; caller `add esp,4` + `test al` |
| Null `DAT_00d1b6d8` → false | **High** | `test ecx / xor al,al / ret` |
| ECX this for callee = global | **High** | `mov ecx,[DAT_00d1b6d8]` then call |
| Callee = `FUN_0052b3b0` journal ready | **High** | rel call + callee dual |
| Body has no stores | **High** | pure forward |
| Clean ≡ raw ≡ live CF | **High** | decompiler `in_EAX&~0xff` ≡ AL clear |
| Sole static xref = detail panel | **High** | `get_xrefs_to` count 1 |
| Complete chrome strings via caller | **High** | `"  [Complete]"`, `"_done"` in `FUN_008a3510` |
| Proposed product name | **Probable** | structural; no retail symbol |
| Global always local player | **Open** | BSS zero in image |

---

## 4. Sealed control flow

```
Client_IsLocalMissionJournalReady(mission) -> bool   // cdecl
  ecx = *(DAT_00d1b6d8)
  if ecx == 0: return false
  return FUN_0052b3b0(this=ecx, mission)             // thiscall ret 4
```

**Caller contract (`FUN_008a3510`):**

| Gate | Effect when true |
|---|---|
| `panel+0x50c == 0` **and** this returns true | append `"_done"` to icon path; append `"  [Complete]"` to title |

---

## 5. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Null global early-out | **Yes** |
| Forward to `0052b3b0` | **Yes** |
| Invented branches / stores | **None** |
| Image thiscall ECX setup | **Yes** (annotated + clean; decompiler elides) |

---

## 6. Gaps / open questions

1. Retail symbol for the wrapper.
2. Product name for owner `FUN_008a3510` (detail panel builder).
3. Runtime: can `DAT_00d1b6d8` point at non-local character?
4. Bit-diff vs retail EXE.

**Verdict:** ABI + null gate + forward **High**. Overall **accept** on CF; **accept-with-gaps** for product naming of wrapper/panel only.
