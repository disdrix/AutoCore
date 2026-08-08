# Review A (reconstruction fidelity): `aa_008b84a0` UI_Mail2dPanel_BuildChrome_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008b84a0` |
| **VA** | `0x008b84a0`–`0x008b8b76` |
| **Canonical name** | `UI_Mail2dPanel_BuildChrome_Inferred` |
| **Ghidra name** | `FUN_008b84a0` |
| **Review date** | `2026-08-05` (R13-013 dual seal) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_008b84a0_UI_Mail2dPanel_BuildChrome_Inferred.md` |
| **System** | inventory-transfer (mail 2d UI chrome builder; no inventory wire authority) |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `disassemble_function`, `read_memory`, callers/xrefs (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Mail 2d panel chrome builder / layout initializer** for `this` panel:

1. SEH + `FUN_00792600`.
2. Load **shared** chrome children via vtbl `+0x404` / close via `+0x408` (`i_d_mail_2d_wnd_*`, `btn_close`, ids).
3. `operator_new(0x81c)` + `FUN_008230b0` twice → **receive tab** `@this+0x55c` (`i_d_mail_2d_tab_receive.xml`, id `0x9c43`) and **send tab** `@this+0x558` (`i_d_mail_2d_tab_send.xml`, id `0x9c42`); parent-attach via vtbl `+0xa8`.
4. Branch on **`this+0x510 == 1`**:
   - **Receive:** load receive frames; construct list (`operator_new(0x560)` → `FUN_008b7240` → `@+0x5a4`); select receive tab / collapse send tab (`FUN_00822cb0` + `FUN_00756c90`); optional **10 s** throttle (`GetTickCount` vs `@+0x50c`) → `FUN_00980250` with dword payload `3`.
   - **Send:** load send/deposit/credits/attachment/item-drop chrome + edits (receiver/subject/message/credits); postage string path; tab-order vtbl `+0x98` indices `0..6`; collapse receive / select send; clear `@+0x518`/`@+0x51c` to `-1`.
5. Final panel layout/refresh vtbl `+0x34c`.

Dispatched only via **DATA vtable** slot `@0x00a475b0` (no direct CALL xrefs).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | Ghidra `decompile_function(0x008b84a0)` 2026-08-05 ≡ frozen raw CF |
| Body / epilogue | `get_function_by_address` body `008b84a0`–`008b8b76`; `disassemble_function` + `read_memory` epilogue plain `RET` |
| ABI | entry `MOV EBP,ECX`; epilogue `ADD ESP,0x14; RET` |
| Xrefs | `get_function_xrefs` / `get_xrefs_to` → **1** DATA `@0x00a475b0` |
| String plates | `read_memory` on push immediates (`i_d_mail_2d_*` family, `"Postage:"`) |
| Dualed callees | R12 duals of `00822cb0` / `00756c90` (call pattern ESI/BL + EDI matches this body) |
| Raw / annotated / clean / records | R13-013 trio refresh |

**Not performed:** `disassemble_bytes`; Launcher; parent ledgers; dual of other VAs / residual callees.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `0x008b84a0`–`0x008b8b76` (1751 B) | **Confirmed** | Ghidra body + epilogue `C3` |
| ABI: **ECX=this**, no stack args, plain **`RET`** | **Confirmed** | `MOV EBP,ECX`; epilogue not `C2 xx` |
| Live decompile ≡ frozen raw CF | **Confirmed** | common chrome → tabs → mode branch → final vtbl |
| Shared chrome loads via vtbl `+0x404` / close `+0x408` id `0x9c40` | **Confirmed** | disasm string ptrs + id immediates |
| Receive tab `@+0x55c` id `0x9c43`; send tab `@+0x558` id `0x9c42` | **Confirmed** | `MOV [EBP+0x55c/558]`; `PUSH 0x9c43/0x9c42` |
| Mode gate `@+0x510 == 1` receive else send | **Confirmed** | `CMP [EBP+0x510],EDI` with `EDI=1` |
| Receive list ctor path `FUN_008b7240` → `@+0x5a4` | **Confirmed** | `operator_new(0x560)` + call |
| Tab select/collapse via dualed `00822cb0` / `00756c90` | **Confirmed** | `MOV ESI,tab; MOV/XOR BL; PUSH 1; CALL 00822cb0` then `MOV EDI,tab; CALL 00756c90` |
| Receive refresh throttle ≥ `0x2710` ms → `FUN_00980250` payload `3` | **Confirmed** | `CMP EAX,0x2710` / `JC`; store tick `@+0x50c` |
| Send control ids `0x9c41`/`0x9c44`/`0x9c46`–`0x9c49` | **Confirmed** | immediates in disasm |
| Sole xref is vtable DATA `@0x00a475b0` | **Confirmed** | no CALL callers |
| Product English class / method name | **Open** | keep `_Inferred` |
| Exact product meaning of `FUN_00980250` payload `3` | **Open** | residual (likely mail list pull; not sealed opcode) |
| Product meaning of vtbl ordinals `+0x404/+0x408/+0x410/+0x34c` | **Open** | residual |
| Runtime / bit-exact | **Open** | no Launcher — **not** Runtime Confirmed |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH + `FUN_00792600` | **Yes** |
| Shared chrome + close | **Yes** |
| Alloc/init receive + send tabs | **Yes** |
| Mode `==1` receive arm (list + select receive + throttle) | **Yes** |
| Mode `!=1` send arm (credits/postage/edits/drop + select send) | **Yes** |
| Final vtbl `+0x34c` both arms | **Yes** |
| No invented inventory C2S in this unit | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| Dense `i_d_mail_2d_*` plate family | **Yes** |
| Receive/send tab dual construction | **Yes** |
| Mode-gated chrome (list vs compose/deposit) | **Yes** |
| Product RTTI / English class | **No** |

**Decision:** promote **`UI_Mail2dPanel_BuildChrome_Inferred`**.  
Prior scaffold alias `UI_mail_bg_frame_deposit` is **rejected** as primary (that string is one send-arm child only).

---

## 6. Gaps

1. Product class / method English (RTTI open).
2. Exact wire role of `FUN_00980250` arg `3` (request family residual).
3. Full slot map for shared chrome `@+0x544..+0x554` product labels.
4. Residual duals of `FUN_008230b0`, `FUN_008b7240`, `FUN_008b6d50`, `FUN_00980250`, postage helpers.
5. Owner type of vtable containing `@0x00a475b0`.
6. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
