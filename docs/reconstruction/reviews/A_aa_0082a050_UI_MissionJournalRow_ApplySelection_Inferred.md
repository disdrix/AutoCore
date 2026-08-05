# Review A (reconstruction fidelity): `aa_0082a050` UI_MissionJournalRow_ApplySelection_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082a050` |
| **VA** | `0x0082a050`–`0x0082a35d` |
| **Canonical name (proposed)** | `UI_MissionJournalRow_ApplySelection_Inferred` |
| **Ghidra name** | `FUN_0082a050` |
| **Prior aliases** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_0082a050` (misleading) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A) |
| **Counterpart** | `reviews/B_aa_0082a050_UI_MissionJournalRow_ApplySelection_Inferred.md` |
| **System tag** | `missions-progression` / journal UI |
| **Agent** | W24-K OWN-ONLY |
| **Verdict** | **accept** on ABI / selection kinds / `(Complete)` wiring; **accept-with-gaps** on product English + kind-2 type |

**Tools:** Ghidra `decompile_function` + `read_memory` + `get_function_xrefs` / `get_function_by_address`. No `disassemble_bytes`. No Launcher. No parent ledger edits.

---

## 1. Purpose

Journal **row selection apply**: store selection triple on the row widget, update title chrome for mission (kind 1) or secondary (kind 2), set complete-label from sealed `IsMissionJournalReady`, layout.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live Ghidra decompile | `FUN_0082a050` @ `0x0082a050` (≡ raw CF) |
| Image bytes | entry `0x0082a050` (64 B); call site `0x0082a248`; epilogue `0x0082a340` |
| Xrefs | 3 CODE: `008a4b84`, `008a558f`, `008a59d8` |
| String | `"(Complete)"` @ `0x00a74368` — sole xref this function |
| Raw / annotated | `raw/aa_0082a050_FUN_0082a050(.annotated).md` |
| Clean | `reconstructed-exact/UI_MissionJournalRow_ApplySelection_Inferred.cpp` |
| Callee dual | `A/B_aa_0052b3b0_CVOGCharacter_IsMissionJournalReady.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `0x0082a050`–`0x0082a35d` | **High** | get_function_by_address |
| ECX=row, EAX=selection triple | **High** | entry `mov edi,eax; mov esi,ecx`; callers `lea eax,stack` |
| Kind0/null clear path | **High** | dual early jz |
| Kind1 `"[%d] %s"` title | **High** | sprintf + mission `+0x11c` level |
| Kind2 title from `p2+0x10` | **High** | CF |
| Complete via `FUN_0052b3b0` | **High** | image call + sealed callee |
| `DAT_00d1b6d8` local character | **High** | shared with journal duals |
| Layout `FUN_00829fa0` always | **High** | both exits |
| Live ≡ raw CF | **High** | re-decompile 2026-07-29 |
| Product class name | **Probable** | widget size 0x534 ctor `FUN_0082a8b0` |
| Kind2 product type | **Tentative** | string payload only |

---

## 4. Sealed control flow

```
ApplySelection(row, sel):
  if !sel or sel.kind_byte==0:
    clear row.+0x500..+0x508; clear +0x4fe
    title set "" + hide; row hide/layout
  else:
    FUN_007a69d0()
    store triple; clear +0x4fe
    if kind==1 and title: format "[level] name"; show; recolor; optional char refresh
    elif kind==2 and title: set text *(p2+0x10); show
    if complete_label:
      text = (p1 && localChar && IsMissionJournalReady(localChar, mission))
            ? "(Complete)" : ""
      sync font from title; layout label
    if aux: aux.vcall(+0xd4); layout; return
  layout  // FUN_00829fa0
```

---

## 5. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Null/kind0 clear | **Yes** |
| Kind1 / kind2 branches | **Yes** |
| Journal-ready complete label | **Yes** |
| Dual layout exits | **Yes** |
| Invented packet / claim path | **None** |

---

## 6. Gaps / open questions

1. Retail symbol for row widget / this function.
2. Kind 2 object type English.
3. Product names for UI vtbl slots `+0x1d8/+0xcc/+0x15c/+0x34c`.
4. Runtime selection triple producer framing beyond `FUN_008a5240`/`FUN_008a4900`.

**Verdict:** Selection apply + `(Complete)` chrome **sealed High**. Overall **accept** / **accept-with-gaps** for naming only.
