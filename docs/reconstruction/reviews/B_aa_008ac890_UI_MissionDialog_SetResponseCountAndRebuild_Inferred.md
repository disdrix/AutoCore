# Review B (skeptical / adversarial): `aa_008ac890` UI_MissionDialog_SetResponseCountAndRebuild_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ac890` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (MEGA-109) |
| **Counterpart** | `reviews/A_aa_008ac890_UI_MissionDialog_SetResponseCountAndRebuild_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs only (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is **NUM_RESPONSE_COLUMNS** setter (`+0x640`) | **Falsified** — stores **`+0x510`** only; columns path in parent writes `+0x640` without calling this |
| 2 | Pure **`__thiscall`** with stack count | **Falsified** — count in **EAX**; bare `RET`; primary site `MOV EAX,[esp+20]; MOV ECX,EDI` |
| 3 | Decompiler void / no params means no inputs | **Falsified** — phantom `in_EAX` + call-site EAX setup; analyze classifies wrapper with phantom local |
| 4 | Clamp is min 8 / floor | **Falsified** — `CMP EAX,8; JLE skip; MOV [..],8` is **max** clamp (`count > 8 → 8`) |
| 5 | Rebuilds item chrome / journal list | **Falsified** — sole callee is dualed **response-button** builder `FUN_008ac110` |
| 6 | Sends C2S / mutates mission tracker | **Falsified** — no packet helpers; UI field + UI rebuild only |
| 7 | EDI is input this on entry | **Falsified as entry ABI** — entry this is **ECX**; unit does `MOV EDI,ECX` for peer EDI-this contract |
| 8 | Product name sealed | **Not supported** — inferred; scaffold Named_CalleeOf retired |
| 9 | Only one caller | **Falsified** — **3** xrefs (`008acb02`, `008ad224`, `0093e6e9`); callers API under-lists unbound sites |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Set `+0x510` + clamp 8 + call rebuild | **High** | Wrong response strip count |
| ECX+EAX register ABI | **High** | Broken hooks / wrong stack frame |
| Peer = BuildResponseButtons | **High** | Wrong chrome path |
| NUM_RESPONSES producer role | **High** | Mis-wire prop dispatch |
| Product English | **Low–Med** | Naming only |
| Max-8 product rationale | **Med** | Layout capacity assumption |

---

## 3. Cross-check contract

```
SetResponseCountAndRebuild(dialog* /*ECX*/, count /*EAX*/):
  dialog[+0x510] = count
  if count > 8: dialog[+0x510] = 8
  BuildResponseButtons(dialog)   // EDI=dialog
  return                         // RET
```

Clean must **not**:

- Write `+0x640` (columns — sibling prop in `FUN_008ac8b0`)
- Invent stack `int count` thiscall
- Claim packet send / mission accept
- Keep `Named_CalleeOf_Named_NUM_RESPONSE_COLUMNS_*` as truth

---

## 4. Surviving contract for AutoCore

```c
struct MissionDialogUi {
  // ...
  int response_count; // +0x510  // max effective 8 after this helper
  // int columns;    // +0x640  // NOT this function
};

// Register ABI — not cdecl stack args
void UI_MissionDialog_SetResponseCountAndRebuild_Inferred(
    MissionDialogUi* dialog /* ECX */,
    int requested_count /* EAX */);
```

Port notes:

- Always pair with `UI_MissionDialog_BuildResponseButtons_Inferred`.
- Callers that hardcode count=1 may write `+0x510` and call Build directly (see `FUN_0093e450` early path) — do not force all paths through this wrapper.
- Cap of **8** is client chrome; do not invent server enum without evidence.

---

## 5. Verdict

**accept-with-gaps** — adversarial attacks on columns-merge / thiscall-stack / min-clamp / packet claims all fail against bytes + dualed peer; residual gaps are product English + runtime only.
