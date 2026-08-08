# Dual A/B report — MEGA-073 OWN-ONLY (`0x0082f810`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-073**  
**Scope:** VA `0x0082f810` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + parent `FUN_0082fe20` decompile/disasm. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — callee of dualed **UI_InteractionMenu_PopulateTargetButtons_Inferred** (`0x0082fe20`): **Add Send Tell** button leaf.  
**Partition:** skills-abilities / interaction-menu residual.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0082f810` UI_InteractionMenu_AddSendTell_Inferred | **accept-with-gaps** — CF/ABI/RET0/EDI-host/strings/id/slot/callers sealed; product host class open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): skill-cast / ECX-thiscall-entry / ret4 / multi-button / convoy-disable / shared-slot claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0082f810` — sealed facts

1. **Body:** `0x0082f810`–`0x0082f849` inclusive (**58 B** / `0x3A`); pad `CC` after.
2. **ABI:** **EDI** = menu host; **no stack args**; void; **`RET`** (`C3`) after `POP ESI`.
3. **Semantics:** interaction-menu **Send a Tell** button pack (single button):
   - `btn = host.vtbl+0x444("i_m_int_2d_btn_generic.xml", 0, 0x11176, -1)` (`MOV ECX,EDI` thiscall into virtual).
   - if `btn`: `btn.vtbl+0x1D8("Send a Tell", 1, 1)`.
   - `host+0x554 = btn` (always, including null).
   - No disable; no crew/leader gate; no direct callees.
4. **Strings:** plate @ `0x00a721ac`; caption @ `0x00a72158` (`read_memory` sealed).
5. **Callees:** none direct; indirect host `vtbl+0x444`, btn `vtbl+0x1D8`.
6. **Callers:** **1** function / **2** UNCONDITIONAL_CALL — dualed parent `FUN_0082fe20` @ `0x0082fedc` / `0x0082ff04` with `MOV EDI,ESI` before both.
7. **Peer:** dualed `UI_InteractionMenu_AddConvoyInviteOrKick_Inferred` `0x0082fb30` (same plate/create/label pattern; ids `0x11171`/`0x11172`; slots `+0x540`/`+0x544`; has disable).
8. **Name:** `UI_InteractionMenu_AddSendTell_Inferred` (Ghidra `FUN_0082f810`). Product host class open → `_Inferred`. Prior plate-only alias `UI_int_btn_generic` retired for role naming.
9. **Decompile ≡ raw CF ≡ full assembly**; ABI/slot sealed via `disassemble_function` + `read_memory` + parent call-site context.

### Gaps

- Product MSVC / RTTI name for menu host class.  
- Product English for create/label vtbl methods and flag args.  
- Downstream command handler for button id `0x11176`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0082f810_UI_InteractionMenu_AddSendTell_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0082f810_UI_InteractionMenu_AddSendTell_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0082f810_FUN_0082f810.md` |
| Annotated | `docs/reconstruction/raw/aa_0082f810_FUN_0082f810.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_InteractionMenu_AddSendTell_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0082f810.cpp` |
| Function | `docs/reconstruction/functions/aa_0082f810_FUN_0082f810.md` |
| Function named | `docs/reconstruction/functions/aa_0082f810_UI_InteractionMenu_AddSendTell_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0082fe20  UI_InteractionMenu_PopulateTargetButtons_Inferred  [dualed]
  ├─ resolve target TFID; gate self/local
  ├─ order depends on menu.vtbl+0x478():
  │     … FUN_0082f8d0 / f9a0 / f810 / fc40 / fa60 / fb30 / fd50 …
  └─ FUN_0082f810  UI_InteractionMenu_AddSendTell_Inferred  [OWN MEGA-073]
        ├─ host.vtbl+0x444(xml, 0, 0x11176, -1)
        ├─ btn.vtbl+0x1D8("Send a Tell", 1, 1)
        └─ host+0x554 = btn

Peer (not OWN):
  FUN_0082fb30  UI_InteractionMenu_AddConvoyInviteOrKick_Inferred  [dualed]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0082f810-mega-073-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0082f810` | Port as **interaction-menu leaf** that creates **"Send a Tell"** button id **`0x11176`** from plate `i_m_int_2d_btn_generic.xml`, labels it, stores at host **`+0x554`**. |
| ABI | **EDI = menu host**, no stack args, **RET 0**. Do **not** model as ECX-thiscall entry (ECX only for nested virtuals). |
| Pair with | dualed parent populate `0082fe20`; dualed convoy peer `0082fb30` (same create/label idiom; different id/slot; peer has disable). |
| Do not | treat as skill-cast/HB; invent chat-send network; merge slots with convoy `+0x540`/`+0x544`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA only when merging:

- `VERIFICATION_MATRIX.md` / coverage / naming as applicable outside this agent.
- Terminal remains **false** until runtime Confirmed.
