# Review A (reconstruction fidelity): `aa_008e5990` UI_CraftHost_BindResolvedObject_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e5990` |
| **VA** | `0x008e5990`–`0x008e5cd0` inclusive (**833 B** / `0x341`) |
| **Canonical name** | `UI_CraftHost_BindResolvedObject_Inferred` |
| **Ghidra name** | `FUN_008e5990` |
| **Review date** | `2026-08-05` (MEGA-032 dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY MEGA-032) |
| **Counterpart** | `reviews/B_aa_008e5990_UI_CraftHost_BindResolvedObject_Inferred.md` |
| **System** | inventory-transfer — craft/RE host bind of resolved object* |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory (+ analyze/xrefs/disassemble_function/assembly_context). **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Bind a **pre-resolved** inventory object pointer (or null) into a craft / reverse-engineering host UI: store `host+0x7cc`, tear down orphan name chrome, clear five material/recipe slots, show or hide selection widgets, rebuild name chrome with a `".geo"` suffix, attach chrome, optionally populate five recipe rows, and refresh host helpers. Parent dual `Client_UI_CraftHost_BindObjectByTfid_Inferred` (`0x008e5ce0`) resolves TFID then calls this unit.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-032 append) | `docs/reconstruction/raw/aa_008e5990_FUN_008e5990.md` |
| Annotated | `docs/reconstruction/raw/aa_008e5990_FUN_008e5990.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_CraftHost_BindResolvedObject_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_008e5990.cpp` |
| Function record | `docs/reconstruction/functions/aa_008e5990_UI_CraftHost_BindResolvedObject_Inferred.md` |
| Live | full disasm; entry/exit hex; DAT_00a28904 = `".geo"`; 5 CALL xrefs with assembly_context |

---

## 3. Signature (sealed)

```c
// ECX = craft/UI host*; stack = object* (nullable); void; RET 4
void __thiscall UI_CraftHost_BindResolvedObject_Inferred(void *host, int *object);
```

| Formal | Source | Conf |
|---|---|---|
| host | **ECX** (`MOV ESI,ECX`; callers `MOV ECX,host`) | **High** |
| object | stack (`MOV EAX,[ESP+0x10]` after SEH push; reloaded as EBX) | **High** |
| return | void (no EAX contract) | **High** |
| cleanup | **`RET 4`** (`C2 04 00`) | **High** |

---

## 4. Control flow (authority)

```text
SEH prolog (LAB_009b2bfa); host+0x7cc = object
if host+0x7d0 && host+0x520==0: delete chrome (vtbl[0](1)); zero +0x7d0
FUN_008e2d60(host)
for i in 0..4: clear slot widgets/companions/TFID pairs @ +0x568/+0x590
zero status +0x7da..+0x7e0
if object == 0:
  hide +0x530/+0x54c; optional +0x520 vtbl+0x44; +0x754 vtbl+0x448(-1,-1)
else:
  show +0x530/+0x54c; +0x754 vtbl+0x448(obj+0x160, obj+0x164)
  chrome = new(0x14c)? FUN_00764030 : 0; host+0x7d0 = chrome
  name: type==0xc → obj vtbl+0x1c0 else FUN_00403450(template+0x10)
  append ".geo" (DAT_00a28904); FUN_00989e00; chrome vtbl+0x5c
  attach +0x520 vtbl+0x40(chrome,1); FUN_007afe80(chrome,1)
  if !FUN_00599dd0(ECX=template): SEH return  // SKIP tail refresh
  FUN_008e5120(...); host+0x7da=1
  if FUN_004ce940() && obj vtbl+0x60()>0: 5× FUN_008e5220 on +0x61c
  FUN_008e4ea0()
FUN_008e55e0(host); FUN_008e47d0(host)
SEH epilogue; RET 4
```

| Stage | Match | Conf |
|---|---|---|
| Store +0x7cc before chrome test | `MOV [ESI+0x7cc],EAX` then TEST +0x7d0 | **High** |
| 5-slot clear | EBX=5; EDI=+0x568; EBP=+0x590; ADD 4/8 | **High** |
| Null vs non-null branch | `TEST EBX; JNZ bind` | **High** |
| Chrome new 0x14c + 764030 | `PUSH 0x14c; CALL operator_new; CALL 764030` | **High** |
| `.geo` append | `MOV EAX,[00a28904]; MOV [EDI],EAX; MOV [EDI+4],CL` | **High** |
| 599dd0 early-out skips 55e0/47d0 | `JZ 008e5cb6` (epilogue) | **High** |
| RET 4 | `C2 04 00` | **High** |

---

## 5. Machine bytes (entry / exit)

| Item | Hex / notes |
|---|---|
| Body | `0x008e5990`–`0x008e5cd0` (**833 B** / `0x341`); pad `CC`×15 then parent `FUN_008e5ce0` |
| Entry | `6A FF 64 A1 00 00 00 00 68 FA 2B 9B 00 50 …` |
| Exit | `5B 64 89 0D 00 00 00 00 81 C4 98 01 00 00 C2 04 00` |
| `.geo` | `read_memory 00a28904` → `2e 67 65 6f 00` |

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers (3) | `FUN_008e5ce0` (×2 sites), `FUN_008e6b50` (×1), `FUN_0093a330` (×2) |
| Xrefs | 5 UNCONDITIONAL_CALL — all `PUSH object\|0; MOV ECX,host; CALL` |
| Callees | `008e2d60`, `operator_new`, `00764030`, `00403450`, free, `00989e00`, `007afe80`, `00599dd0`, `008e5120`, `004ce940`, `008e5220`, `008e4ea0`, `008e55e0`, `008e47d0`, many vtbls |

---

## 7. Gaps

1. Product demangle for craft host / chrome / widget classes (no RTTI in unit).  
2. Residual helper English (`008e2d60`, `008e5120`, `008e5220`, `008e4ea0`, `008e55e0`, `008e47d0`, `00599dd0`, `004ce940`, `007afe80`).  
3. Exact product meaning of type tag `0xc` vs template-string name path.  
4. SSO/string layout of `FUN_00403450` path — CF sealed, struct English open.  
5. Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity path seals thiscall host + stack object + RET 4, store/clear/bind CF, five-slot teardown, `.geo` name chrome, attach, 599dd0 early-out (skips tail refresh), and all five call sites from dualed TFID parent + two residual parents. Residual product English + helper duals → **accept-with-gaps**.
