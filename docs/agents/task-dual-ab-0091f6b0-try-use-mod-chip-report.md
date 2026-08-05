# Dual A/B report — `aa_0091f6b0` Client_Input_TryUseModChip

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x0091f6b0`. Dual A/B + three-rep. Seal mod-chip input CF + C2S **`0x202c`**.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / ledgers.  
**Ghidra:** `decompile_function` + `disassemble_function` + `read_memory` (+ callers/xrefs/assembly_context). No `disassemble_bytes`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0091f6b0` Client_Input_TryUseModChip | **accept-with-gaps** — opcode **`0x202c`**, dual callers, validate/bypass CF **sealed** |

---

## Sealed facts

1. **ABI:** `__fastcall`, **`EDX = client*`** (writes `client+0xc2c`); ECX unused; void; `RET` after `ADD ESP,0x118`.

2. **Entry gates:** `DAT_00d1b6d8 != 0`, `*(DAT_00d1b644+0xf5)==0`, `*(player+0x6bb)==0`. On pass: **`*(client+0xc2c) = 9999999`** (`0x98967f`).

3. **Path A (`player+0x6b9 != 0`):** send sector packet **opcode `0x202c`**, size **`0x18`**, TFID from multi-inherit **`+0x164`** — **no** LocalCastValidate.

4. **Path B:** require vehicle `@player+0x250` and **`FUN_0040ce50(vehicle) != -1`**. Else modal **`"You have no mod chip!"`** via `FUN_007fdfb0`.  
   Else skill = `FUN_0040ce50`; `skipBusy = char.vtbl[+0x234]()`; `Skill_LocalCastValidate(char, null, skipBusy, skill)`.  
   - **`rc == 0`:** send same **`0x202c`** packet (asm seals opcode @ `0x0091f7ac`; decompiler stack name residual).  
   - **else:** `Skill_FormatFailureMessage` + optional `FUN_008f8200` if `DAT_00d1b8dc`.

5. **`FUN_0040ce50`:** sole caller = this unit; `vehicle+0x270` null → `-1`; else nested read **`…+0x3bc`** (mod-chip skill binding).

6. **Callers (exactly two):**
   - `Client_Input_DriveControlTick` @ `0x00923666` — ActionMap **`DAT_00d1cafa`** + edge **`DAT_00d1cafb`** (cleared); `MOV EDX,EBX`.
   - `FUN_008c50f4` @ `0x008c5132` — UI path (`0x9c40`/case-8 sibling); gated by `DAT_00d1b778` vtbl **`+0x3d8`** when not the `+0x6b8 && !+0x6b9` → `FUN_008c4fc0` branch.

7. **Not** RequestCast `0x2030`, not drive-axis Push, not secondary-weapon heat fire.

8. **Name:** `Client_Input_TryUseModChip` (**INFERRED**). Deprecate sole-name `Named_CalleeOf_Client_Input_DriveControlTick_0091f6b0`.

---

## Gaps

1. English for `+0x6b9` / `+0x6bb` / `DAT_00d1b644+0xf5` / ActionMap `DAT_00d1cafa`.  
2. Packet **+4** unwritten dword meaning.  
3. `FUN_0040ce50` product name; skill object* vs id at `+0x3bc`.  
4. Consumer of `client+0xc2c`.  
5. Product/PDB symbol; live `0x202c` capture; bit-exact / diff.  
6. Full product name of UI parent `FUN_008c50f4`.

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0091f6b0_Client_Input_TryUseModChip.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0091f6b0_Client_Input_TryUseModChip.md` |
| Function record | `docs/reconstruction/functions/aa_0091f6b0_Client_Input_TryUseModChip.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_Input_TryUseModChip.cpp` |
| Raw (authoritative + residual) | `docs/reconstruction/raw/aa_0091f6b0_FUN_0091f6b0.md` |
| Annotated | `docs/reconstruction/raw/aa_0091f6b0_FUN_0091f6b0.annotated.md` |
| Scratch | `tmp/a_0091f6b0.md` |
| This report | `docs/agents/task-dual-ab-0091f6b0-try-use-mod-chip-report.md` |

Legacy scaffold (name superseded):  
`functions/aa_0091f6b0_FUN_0091f6b0.md`, `reconstructed-exact/FUN_0091f6b0.cpp`,  
`Named_CalleeOf_Client_Input_DriveControlTick_0091f6b0.cpp`.

Related parent: `docs/reconstruction/systems/input-drive-control.md` (`Client_Input_DriveControlTick`); skills duals for LocalCastValidate / FormatFailureMessage.

---

## AutoCore impact

- Mod-chip is a **dedicated C2S `0x202c`** self-TFID packet, not folded into RequestCast `0x2030` or weapon fire.
- Input bind edge is **`DAT_00d1cafa`/`cafb`** inside DriveControlTick (sibling to axis Push — do not merge).
- Client must preserve **`+0x6b9` validate-bypass** and **"You have no mod chip!"** when `FUN_0040ce50` fails.
- Server remains authority; this unit is optimistic client UX + send only.
