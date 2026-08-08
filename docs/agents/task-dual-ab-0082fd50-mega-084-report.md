# Dual A/B report — MEGA-084 OWN-ONLY (`0x0082fd50`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-084**  
**Scope:** VA `0x0082fd50` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + callers/xrefs + `disassemble_function` + `read_memory` + parent `FUN_0082fe20` disasm. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-084**.  
**Hint:** `UI_InteractionMenu_AddNameplateLabel` (parent `0x0082fe20`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0082fd50` UI_InteractionMenu_AddNameplateLabel_Inferred | **accept-with-gaps** — CF/ABI/id/slot/colors/call sites sealed; product host class + `+0x6B4`/color English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): cast-residual / thiscall / fixed-string-action / plate-as-product claims **falsified**; nameplate role **High**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0082fd50` — sealed facts

1. **Body:** `0x0082fd50`–`0x0082fe20` exclusive (**208 B** / `0xD0`); next fn `FUN_0082fe20` tight (`56 8B F1`); **no** `CC` pad. Epilogue **`pop esi; pop ebp; add esp,8; ret`** → **`ret 0`**.

2. **ABI:** parent-preserved registers (decompiler `unaff_EDI` / `unaff_EBX`):
   - **EDI** = menu host* (`mov edi,esi` in parent)
   - **EBX** = owner/target* (`mov ebx,ebp` where EBP = `target.vtbl+0x210(0)`)
   - **Not** standard thiscall; no stack args beyond local color buffer.

3. **Semantics:** **Interaction-menu nameplate label pack**:
   - Display name via object adj/RTTI chain + **`vtbl+0x160`**.
   - Create button: host **`vtbl+0x444`**(`"i_m_int_2d_btn_generic.xml"`, `0`, **`0x1117F`**, `-1`) — plate @ `0x00A721AC`.
   - Label: btn **`vtbl+0x1D8`**(name, 1, 1).
   - Store: host **`+0x53C`** (`EDI[0x14F]`).
   - Always **`vtbl+0xD4(0)`** (non-interactive display).
   - Color by **`target+0x6B4`**: `<1` → **`0xFF1EA0B4`**; else **`0xFFA01EB4`**; **`vtbl+0x15C`(1, &color)**.
   - **`btn+0x170 = 0xFFFFFFFE`**; **`vtbl+0x1E4`(1)**.

4. **Callers (1 fn, 2 sites):** `FUN_0082fe20` / `UI_InteractionMenu_PopulateTargetButtons_Inferred`:
   - `0x0082FEC0` — Name-first pack order (`vtbl+0x478 != 0`)
   - `0x0082FF22` — Name-last pack order (`vtbl+0x478 == 0`)

5. **Xrefs:** 2 UNCONDITIONAL_CALL only (same sites).

6. **Callees:** none direct (vtbl leaf). `analyze_function_complete` classification: **leaf**.

7. **Name:** `UI_InteractionMenu_AddNameplateLabel_Inferred` (Ghidra `FUN_0082fd50`). Role **High** (dynamic name + always-disable + parent “Name” pack position); product class open → **`_Inferred`**. Supersedes plate-only `UI_int_btn_generic_0082fd50`.

8. **Decompile ≡ raw CF** (live 2026-08-05 ≡ frozen 2026-07-23). Asm seals 4-arg create that decompiler elides.

### Gaps

- Product menu-host class / MSVC name.  
- English for `+0x6B4` and the two ARGB colors.  
- English for `vtbl+0x15C` / `+0x1E4` / `btn+0x170`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0082fd50_UI_InteractionMenu_AddNameplateLabel_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0082fd50_UI_InteractionMenu_AddNameplateLabel_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0082fd50_FUN_0082fd50.md` |
| Annotated | `docs/reconstruction/raw/aa_0082fd50_FUN_0082fd50.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/UI_InteractionMenu_AddNameplateLabel_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0082fd50.cpp` |
| Function scaffold | `docs/reconstruction/functions/aa_0082fd50_FUN_0082fd50.md` |
| Function named | `docs/reconstruction/functions/aa_0082fd50_UI_InteractionMenu_AddNameplateLabel_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0082fe20  UI_InteractionMenu_PopulateTargetButtons_Inferred  [dualed prior]
  ├─ shell rebuild FUN_0082d2b0
  ├─ resolve TFID @ host+0x578 → target
  ├─ owner = target.vtbl+0x210(0)  (must exist, != local)
  ├─ pack order via host.vtbl+0x478:
  │     flag==0: Ignore, Friends, Tell, Trade, Clan, Convoy, Name
  │     flag!=0: Name, Convoy, Clan, Trade, Tell, Friends, Ignore
  ├─ FUN_0082fd50  UI_InteractionMenu_AddNameplateLabel_Inferred  [OWN MEGA-084]
  │     ×2 sites 0x0082FEC0 / 0x0082FF22
  ├─ FUN_0082fb30  UI_InteractionMenu_AddConvoyInviteOrKick_Inferred  [dualed]
  └─ sibling packs f8d0/f9a0/f810/fc40/fa60 (residual / partial)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0082fd50-mega-084-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0082fd50` | Port as **interaction-menu nameplate label** widget factory, not cast residual. |
| ABI | **EDI=menu**, **EBX=owner/target**, **ret 0**. Preserve parent register contract. |
| Create | `vtbl+0x444(xml, 0, 0x1117F, -1)`; plate `i_m_int_2d_btn_generic.xml`. |
| Label | Dynamic object name via **`vtbl+0x160`** — not a fixed string. |
| Slot | Host **`+0x53C`**. Always disable via **`vtbl+0xD4(0)`**. |
| Color | `+0x6B4 < 1` → `0xFF1EA0B4`; else `0xFFA01EB4`; then `btn+0x170=-2`, `vtbl+0x1E4(1)`. |
| Pair with | dualed parent populate `0082fe20`; dualed convoy pack `0082fb30`; sibling social packs. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md` / system map entry (skills-abilities residual UI nameplate)
- coverage / inventory progress rows

**Terminal:** false.
