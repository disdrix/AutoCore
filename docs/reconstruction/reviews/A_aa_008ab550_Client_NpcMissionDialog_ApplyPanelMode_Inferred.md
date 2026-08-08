# Review A (reconstruction fidelity): `aa_008ab550` Client_NpcMissionDialog_ApplyPanelMode_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ab550` |
| **VA** | `0x008ab550`–`0x008ab799` inclusive (**586 B** / `0x24A`) |
| **Canonical name** | `Client_NpcMissionDialog_ApplyPanelMode_Inferred` |
| **Ghidra name** | `FUN_008ab550` |
| **Review date** | `2026-08-05` (MEGA-051 dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY MEGA-051) |
| **Counterpart** | `reviews/B_aa_008ab550_Client_NpcMissionDialog_ApplyPanelMode_Inferred.md` |
| **System** | missions-progression — NPC mission dialog panel mode / multi-mission fill |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + analyze + disassemble_function + read_memory + callers/xrefs + assembly_context. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Apply panel mode on the NPC mission dialog host:

- Store mode at `dialog+0x648`.
- Mode **0/3**: clear `+0x670`, clear flag `+0x580`, hide response/single-mission chrome (including 16-slot grid at `+0x698..+0x6d4`).
- Mode **1/2**: clear TFID pair `+0x678/+0x67c` to `−1`, **show** widgets `+0x6f8/+0x6fc`.
- Mode **3 only**: fill title widget `+0x6dc` with localized **`"Select a Mission:"`**, style 10, viewport-scaled size, color `DAT_00afdf0c`, layout refresh.
- Always call residual list-row clear `FUN_008ab340` (ESI=dialog).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-051 append) | `docs/reconstruction/raw/aa_008ab550_FUN_008ab550.md` |
| Annotated | `docs/reconstruction/raw/aa_008ab550_FUN_008ab550.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_NpcMissionDialog_ApplyPanelMode_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_008ab550.cpp` |
| Function record | `docs/reconstruction/functions/aa_008ab550_Client_NpcMissionDialog_ApplyPanelMode_Inferred.md` |
| Live | decompile ≡ scaffold CF; full disasm; body bounds; 3 CALL xrefs; float/string/`DAT_00afdf0c` bytes |

---

## 3. Signature (sealed)

```c
// ECX = dialog*; EAX = panelMode {0,1,2,3}; void; plain RET
void Client_NpcMissionDialog_ApplyPanelMode_Inferred(void *dialog /* ECX */, int panelMode /* EAX */);
```

| Formal | Source | Conf |
|---|---|---|
| dialog | **ECX** → `MOV ESI,ECX` | **High** |
| panelMode | **EAX** → `MOV EDI,EAX` **before** locale call; store `[ESI+0x648]` | **High** |
| stack | none | **High** |
| return | void | **High** |
| cleanup | plain **`RET`** (`C3`) both exits (`008ab6cc`, `008ab799`) | **High** |

---

## 4. Control flow (authority)

```text
locale = Locale_GetInstance()          // FUN_007a69d0 → EBP
dialog+0x648 = mode                    // EDI (entry EAX)
if mode∈{0,3}: dialog+0x670 = 0
else if mode∈{1,2}: dialog+0x678 = dialog+0x67c = -1
if mode∈{0,3}:
  dialog+0x580 = 0
  hide dialog+0x6e8
if title = dialog+0x6dc:
  show(title, mode != 0)
  if mode == 3:
    style(title, 10)
    scale title+0x170/174 from +0x1b8/1bc × viewport × DAT_00aaa67c/678
    text = StringPool(..., "Select a Mission:", -1)  // this=locale
    setText(title, text, 1, 1); setColor(... DAT_00afdf0c); layout()
if mode∈{0,3}:
  hide chrome group + 4×4 grid; if mode==3 hide +0x6f8; hide +0x6fc
else:
  show +0x6f8; if +0x6fc: show(1); FUN_008ab340(); return
FUN_008ab340()
```

| Stage | Match | Conf |
|---|---|---|
| Entry EDI=mode, ESI=dialog | `8B F8 8B F1` | **High** |
| Locale before mode store | `CALL 007a69d0; MOV EBP,EAX; MOV [ESI+0x648],EDI` | **High** |
| Mode 0/3 vs 1/2 branches | CMP/JZ ladder | **High** |
| Mode-3 title fill string | `PUSH -1; PUSH 0xa4aba0; MOV ECX,EBP; CALL 007a6de0` | **High** |
| Scale floats | MULSS `DAT_00d1e818/1c` × `DAT_00aaa67c/678` | **High** |
| 4×4 hide loop | `LEA EDI,[ESI+0x6c8]; MOV EBP,4` | **High** |
| Tail FUN_008ab340 | both exits; ESI preserved | **High** |
| Plain RET | `5F 5E 5D C3` | **High** |

---

## 5. Machine bytes (entry / exit / constants)

| Item | Hex / notes |
|---|---|
| Body | `0x008ab550`–`0x008ab799` (**586 B** / `0x24A`); pad `CC`×6 |
| Entry | `55 56 57 8B F8 8B F1 E8 …` |
| Exit (both) | `… CALL 008ab340; 5F 5E 5D C3` |
| String | `0x00a4aba0` = `"Select a Mission:"` |
| Scale | `DAT_00aaa67c≈0.000625`, `DAT_00aaa678≈0.000833` |
| Color | `DAT_00afdf0c` = `FFFFFFFF 00FFFFFF …` |

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers (3 CALL) | `Client_ShowNpcMissionDialogUI` @ `00943972` (**EAX=3**), @ `00943a6c` (**EAX=1**); `FUN_0093e450` @ `0093e623` (**EAX=0**) |
| Callees | `Locale_GetInstance_Inferred` (`007a69d0`), `StringPool_ApplyModeAndRingStore_Inferred` (`007a6de0`), `FUN_008ab340`, widget vtbls |

---

## 7. Gaps

1. Product / PDB demangle for dialog class and widget slots.  
2. Mode **1 vs 2** product English (same chrome path in this unit).  
3. Runtime viewport `DAT_00d1e818/1c` values + visual scale proof.  
4. Dual of residual `FUN_008ab340` (MEGA-105).  
5. Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity pass seals ABI (ECX dialog + EAX mode + plain RET), mode table, mode-3 multi-mission title fill, caller framing, and decompiler locale/mode lag correction. Product English and residual list helper remain open → **accept-with-gaps**.
