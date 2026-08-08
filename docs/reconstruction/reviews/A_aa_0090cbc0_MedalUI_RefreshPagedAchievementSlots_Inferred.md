# Review A (reconstruction fidelity): `aa_0090cbc0` MedalUI_RefreshPagedAchievementSlots_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090cbc0` |
| **VA** | `0x0090cbc0`–`0x0090cdfe` inclusive (**575 B** / `0x23F`) |
| **Canonical name** | `MedalUI_RefreshPagedAchievementSlots_Inferred` |
| **Ghidra name** | `FUN_0090cbc0` |
| **Review date** | `2026-08-05` (MEGA-063 dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY MEGA-063) |
| **Counterpart** | `reviews/B_aa_0090cbc0_MedalUI_RefreshPagedAchievementSlots_Inferred.md` |
| **System** | missions-progression — medal/achievement UI paged refresh |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` + `get_function_xrefs` + `get_assembly_context` + `read_memory` + `get_function_signature`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory (+ analyze/xrefs/disassemble_function/assembly_context). **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Rebuild the paged medal/achievement button grid on a MedalUI host: gate on manager + visibility, prep-clear 24 slots, count medals, update page/scrollbar state, then fill up to 24 achievement buttons from the current page (vector source flag=1, hash source flag=0). Primary post–force-complete caller is S2C `0x2070` `Client_RecvCompleteDynamicObjective`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-063 append) | `docs/reconstruction/raw/aa_0090cbc0_FUN_0090cbc0.md` |
| Annotated | `docs/reconstruction/raw/aa_0090cbc0_FUN_0090cbc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MedalUI_RefreshPagedAchievementSlots_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0090cbc0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0090cbc0_MedalUI_RefreshPagedAchievementSlots_Inferred.md` |
| Live | full disasm listing; entry hex; 6 xrefs; call-site assembly_context |

---

## 3. Signature (sealed)

```c
// EAX = MedalUI host*; no stack formals; void; bare RET
void MedalUI_RefreshPagedAchievementSlots_Inferred(void);
```

| Formal | Source | Conf |
|---|---|---|
| host | **EAX** (`MOV ESI,EAX` @ `0090cbcd`; all call sites seed EAX) | **High** |
| stack formals | none | **High** |
| return | void (no EAX produce; bare `RET`) | **High** |
| cleanup | **`RET`** (`C3`) @ `0090cde0` / `0090cdfe` | **High** |

---

## 4. Control flow (authority)

```text
manager = DAT_00d1b6d8; if 0: return
if host->vtbl[+0x3d8]() == 0: return          // ECX=host
EDI=host; CALL FUN_0090c700                   // prep clear 24 slots
filled=0; EBX=manager; count=FUN_0090c810()
if count <= 0:
  host+0x50c = 0
  if scrollbar(host+0x5a0): vtbl[+4](0)
  return
maxPage = (count-25)/3 + 1                    // magic 0x55555556
host+0x5a4 = maxPage
if count <= 24: maxPage=0; pageIndex=0
else if pageIndex > maxPage: pageIndex = maxPage
if scrollbar:
  if maxPage==0: vtbl[+0xcc](0)
  else: vtbl[+0xcc](1); vtbl[+0x460](1.0f/maxPage)
  vtbl[+0x34c]()
walkIndex=-1
// vector [manager+0x574, +0x578): resolve 0051a0e0; if idx>=page*3: 0090c9a0(m,1)
// hash manager+0x540 lock+0x1d: resolve payload+0x100; 0090c9a0(m,0)
// unlock; return
```

| Stage | Match | Conf |
|---|---|---|
| Manager + visible gates | `TEST EBX; JZ` / `CALL [EAX+0x3d8]; TEST AL; JZ` | **High** |
| Prep clear 0090c700 | `MOV EDI,ESI; CALL 0090c700` | **High** |
| Count 0090c810 | `CALL 0090c810; CMP ECX,0; JLE zero` | **High** |
| Page math / clamp | `IMUL 55555556` / `CMP ECX,18; JG` / stores `+0x5a4`/`+0x50c` | **High** |
| Scrollbar vcalls | `+0xcc` / `+0x460` / `+0x34c` / zero-path `+4` | **High** |
| Vector fill flag=1 | `PUSH 1; PUSH medal; CALL 0090c9a0` | **High** |
| Hash fill flag=0 | lock `+0x1d`; `PUSH 0; PUSH medal; CALL 0090c9a0` | **High** |
| Slot cap 0x18 / stride 3 | `CMP EBP,18` / `LEA ECX,[ECX+ECX*2]` | **High** |
| Bare RET | `C3` both exits; pad `CC` then next fn | **High** |

---

## 5. Machine bytes (entry / exit)

| Item | Hex / notes |
|---|---|
| Body | `0x0090cbc0`–`0x0090cdfe` (**575 B** / `0x23F`); pad `CC` @ `0090cdff` |
| Entry | `83 EC 0C 53 8B 1D D8 B6 D1 00 … 8B F0` |
| Exit | `… 5E 5B 83 C4 0C C3` |

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Xrefs | **6** (5 CALL + 1 JMP) |
| Primary | `Client_RecvCompleteDynamicObjective` @ `0081015f` — `MOV EAX,[EDI+0x1034]; MOV EAX,[EAX+0x514]; CALL` |
| Tail | `FUN_0080ce50` @ `0080ce87` **JMP** with EAX=host |
| Window | `FUN_0090d0d0` @ `0090d364` (achievements XML) |
| Others | `FUN_00946c00` @ `009473a5`; `0090ce73`; `00952bb1` |
| Callees | `FUN_0090c700`, `FUN_0090c810`, `FUN_0051a0e0`, `FUN_0090c9a0`, `FUN_007a4480` |

---

## 7. Gaps

1. Product demangle for MedalUI host / `DAT_00d1b6d8` manager / scrollbar widget classes.  
2. Product English for vtbl `+0x3d8` / `+0xcc` / `+0x460` / `+0x34c` / `+4`.  
3. Apply `flag` 0 vs 1 product meaning beyond source path (vector vs hash).  
4. Dual of residual callers `FUN_00946c00` / site owners — not OWN.  
5. Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity path seals **EAX-host ABI**, bare **RET**, body size, manager/visible gates, prep→count→page→scrollbar→dual-source fill CF, 24-slot / stride-3 paging, and post-`0x2070` caller. Residual product English + helper/caller duals → **accept-with-gaps**.
