# Review B (skeptical / adversarial): `aa_0090d390` Client_Input_FindFirstActiveUiWindowTable5_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090d390` |
| **VA** | `0x0090d390`–`0x0090d3c4` inclusive (**53 B** / `0x35`) |
| **Canonical name** | `Client_Input_FindFirstActiveUiWindowTable5_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (MEGA-096 OWN dual) |
| **Counterpart** | `reviews/A_aa_0090d390_Client_Input_FindFirstActiveUiWindowTable5_Inferred.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `read_memory` + call-site `get_assembly_context` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is the ActionMap / keybind table scan (`DAT_00d1bc18`) | **Falsified** — table base is **`DAT_00d09a38`**, 5 dwords; keybind scan is parent body with stride 0x34 |
| 2 | This is the dismiss walker itself (`0x0090dab0`) | **Falsified** — body only finds+returns; dismiss is sibling that calls `FUN_0090d400` ×5 |
| 3 | Returns void / only sets a flag | **Falsified** — EAX = slot pointer or 0; both callers `TEST EAX` |
| 4 | `thiscall` with ECX = client host | **Falsified** — no entry ECX use; ECX loaded from table slot for vcall only; bare RET |
| 5 | RET 4 / stdcall stack args | **Falsified** — both exits plain **`C3`** |
| 6 | Unbounded walk / variable count | **Falsified** — hard `CMP ESI,5` / `JL` |
| 7 | Product scaffold name is role | **Falsified** — Named_CalleeOf plate is parent-seed only; multi-caller (OnKeyDown + `FUN_0092cef0`) |
| 8 | Same as nested helper `0x0090dab0` merge | **Falsified** — different ABI (return window* vs void EAX-host), different body size (53 B vs 38 B) |
| 9 | Calls named FUN callees | **Falsified** — only indirect vtbl+0x3d8; callees list empty |
| 10 | Decompiler invents loop / wrong bound | **Falsified** — bytes seal 5-iteration index loop and both RET paths |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 5-slot table bounds | **High** | Wrong registry size / OOB |
| Active gate vtbl+0x3d8 | **High** | Wrong UI visibility test |
| ABI bare RET / EAX return | **High** | Stack corrupt or drop return |
| Distinct from dismiss walker | **High** | Port merges find+dismiss |
| Not keybind ActionMap scan | **High** | Wrong table / input path |
| Product window English | Medium | Naming only |
| Secondary caller full role | Medium | Incomplete call-graph English |

---

## 3. Cross-check against raw + bytes

```
ESI = 0
loop:
  if DAT_00d09a38[ESI] == 0: goto next
  ECX = DAT_00d09a38[ESI]
  AL  = [ECX->vtbl + 0x3d8]()   // thiscall
  if AL != 0:
    EAX = DAT_00d09a38[ESI]
    POP ESI; RET
next:
  ESI++
  if ESI < 5: goto loop
  EAX = 0
  POP ESI; RET
```

Bytes seal:

- Table base `38 9a d0 00` at every scaled-index access.
- `CMP ESI,5` / `JL` bound.
- `CALL [EAX+0x3d8]` (`ff 90 d8 03 00 00`).
- Hit path `MOV EAX,[ESI*4+table]` then `POP ESI; RET`.
- Miss path `XOR EAX,EAX; POP ESI; RET`.

Do **not** merge with:

- `aa_0090dab0` `Client_Input_DismissUiWindowTable5_Inferred` (dismiss walker; EAX=host)
- `aa_0090d400` per-slot dismiss (ESI window / EDI host)
- Parent keybind scan over `DAT_00d1bc18` / `DAT_00d1bbee`
- ActionMap override lookup `FUN_007f6db0`

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape — ESC any-active UI window gate (5-slot registry)
object? FindFirstActiveUiWindowTable5()
{
    for (int i = 0; i < 5; i++)
    {
        var w = UiWindowTable5[i]; // DAT_00d09a38
        if (w == null) continue;
        if (w.IsActiveOrVisible()) // vtbl+0x3d8 — product English open
            return w;
    }
    return null;
}
```

Call after ESC client-gate and flag+`0x50d` set; if non-null, call dismiss walker with **client host in EAX** (not the window*).

**Verdict:** **accept-with-gaps**
