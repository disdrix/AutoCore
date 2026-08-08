# Dual A/B report — WQ8R-G OWN `aa_00571db0` + `aa_0080d570`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual WQ8R-G  
**Scope:** VAs `0x00571db0`, `0x0080d570` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Wave:** WQ-008 residual (inventory-transfer priority 94).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00571db0` InventoryGrid_RemoveItemAtXY | **accept-with-gaps** — CF + ABI + `height*x+y` index + Find→Remove(1,0) sealed; **0** static callers |
| `aa_0080d570` Client_RecvOpenAvailableGadgetResponse | **accept-with-gaps** — S2C **0x20A8** + dual-grid find + fail enum/success CF sealed; kit-host MI residual |

---

## VA `0x00571db0` — sealed facts

1. **Body:** `0x00571db0`–`0x00571e0e` (**94 B**; pad `CC` after last RET).
2. **ABI:** **ECX**=`InventoryGrid*`; stack `uint8 x`, `uint8 y`; **EAX**=`ItemObject*|null`; `RET 0x08`.
3. **Semantics:** If in-bounds, load cell COID stamp → `InventoryGrid_FindItemByCoid` → `InventoryGrid_RemoveItem(item, 1, forceFull=0)`.
4. **Bounds:** `x < *(grid+0x08)` (width); `y < *(grid+0x0c)` (height); else return 0.
5. **Index:** `index = height * x + y` (same family as Place/Remove footprint packing).
6. **Cells:** `*(grid+0x28)` base; entry stride **8** (COID lo/hi).
7. **Stack setup:** `push 0; push 1` *before* Find so Remove receives qty=1, forceFull=0 after Find’s `RET 8`.
8. **Callees (2):** `0x00571010` FindItemByCoid; `0x00571b80` RemoveItem (both dual-sealed prior).
9. **Callers:** **none** in Ghidra static xref DB (gap / possible dead).
10. **Name:** `InventoryGrid_RemoveItemAtXY` (Ghidra `FUN_00571db0`; **Inferred**).
11. **Sibling:** thin `FUN_00571d80` = FindByCoid + Remove(item,1,forceFromArg).
12. **Decompile ≡ bytes** for CF (live 2026-08-04 ≡ raw 2026-07-23).

### Gaps

- Product/PDB name.  
- Static/runtime callers (0 CALL xrefs).  
- Runtime / bit-exact; empty-cell (`-1,-1`) path depends on Find/Remove gates.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00571db0_InventoryGrid_RemoveItemAtXY.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00571db0_InventoryGrid_RemoveItemAtXY.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00571db0_FUN_00571db0.md` |
| Annotated | `docs/reconstruction/raw/aa_00571db0_FUN_00571db0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/InventoryGrid_RemoveItemAtXY.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00571db0.cpp` |
| Function | `docs/reconstruction/functions/aa_00571db0_FUN_00571db0.md` |
| Function named | `docs/reconstruction/functions/aa_00571db0_InventoryGrid_RemoveItemAtXY.md` |
| Scratch | `docs/reconstruction/tmp/a_00571db0.md` |

---

## VA `0x0080d570` — sealed facts

1. **Body:** `0x0080d570`–`0x0080d915` (**933 B**); frame `SUB ESP,0x104`; epilogue `ADD ESP,0x104; RET 4`.
2. **ABI:** stack `packet*`; **ESI**=`ClientContext*` (PacketDispatch custom); void return.
3. **Wire:** S2C opcode **`0x20A8`** — dispatch label **OpenAvailableGadgetResponse**.
4. **Sole caller:** `Client_PacketDispatch` @ `0x00815d1e` (xref_count **1**).
5. **Gates:** require `*(ESI+0xe98)` character and `*(char+0x250)` cargo host.
6. **Item resolve (asm):** FindItemByCoid on **cargo** `*(*(char)+0x250)+0x2b0`; if null, **locker** `*(char)+0xcbc` (DropResponse types **1** / **3**). Decompiler collapses this — **bytes win**.
7. **Kit resolve:** `CVOGReaction_ResolveObjectTarget(1, pkt+0x18, pkt+0x1c)` then vtbl **`+0x200`** cast-as-TinkeringKit.
8. **Packet fields:** COID `@+0x10/14`; kit id `@+0x18/1c`; fail reason `@+0x28`; success `@+0x2c`; catastrophic `@+0x2d`.
9. **Success:** open-slot counter++ (item vtbl `+0x8c`/`+0x90`); toast “Tinkering successful…”; SFX `tinker_success`.
10. **Fail:** SFX `tinker_fail`; switch reason **1–4** product strings; case **4**+catastrophic → destroy toast + `RemoveItem(item,1,1)` if still contained.
11. **Shared post:** attempt kit remove if still in kit inventory host; `FUN_00933310`; `Client_RefreshOpenMissionUiWindows`.
12. **Name:** `Client_RecvOpenAvailableGadgetResponse` (Ghidra `FUN_0080d570`).
13. **Decompile ≡ raw** for high-level CF; dual-grid this restored from entry bytes.

### Gaps

- Kit inventory host MI expression for final RemoveItem.  
- Success sprintf full vararg packing.  
- Full packet size / unused fields.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0080d570_Client_RecvOpenAvailableGadgetResponse.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0080d570_Client_RecvOpenAvailableGadgetResponse.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0080d570_FUN_0080d570.md` |
| Annotated | `docs/reconstruction/raw/aa_0080d570_FUN_0080d570.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RecvOpenAvailableGadgetResponse.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0080d570.cpp` |
| Function | `docs/reconstruction/functions/aa_0080d570_FUN_0080d570.md` |
| Function named | `docs/reconstruction/functions/aa_0080d570_Client_RecvOpenAvailableGadgetResponse.md` |
| Scratch | `docs/reconstruction/tmp/a_0080d570.md` |
| Prior scaffold alias | `Inv_BUG_Item_to_tinker_not_found_Server_thinks_it_wo_0080d570.cpp` (superseded by named clean) |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00571db0` | Cell-coordinate remove wrapper — preserve `height*x+y`, forceFull=**0**, qty=**1**; do not assume always full unstamp (RemoveItem peel). Low urgency if truly unreferenced. |
| `0080d570` | S2C **0x20A8** gadget open-slot response — dual-grid cargo→locker find; success mutates open-slot counter client-side; fail codes 1–4; catastrophic case 4 removes item with forceFull=1. Pair with any C2S open-slot request if ported later. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ xrefs). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) filed per VA.  
- Trio (raw/annotated/function) refined; clean named + FUN_ twins.  
- This report: `docs/agents/task-dual-ab-00571db0-0080d570-wq8rg-report.md`
