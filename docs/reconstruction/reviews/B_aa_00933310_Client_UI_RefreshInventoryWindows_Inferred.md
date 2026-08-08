# Review B (skeptical / adversarial): `aa_00933310` Client_UI_RefreshInventoryWindows_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00933310` |
| **VA** | `0x00933310` |
| **Canonical name** | `Client_UI_RefreshInventoryWindows_Inferred` |
| **Review date** | `2026-08-05` (MEGA-099 dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00933310_Client_UI_RefreshInventoryWindows_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `read_memory` + `disassemble_function` + analyze/xrefs + assembly context + callee dual cross-check |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Decompiler `void FUN_00933310(void)` is complete ABI | **Falsified** — 5 stack args, EAX key, CL flag, `RET 0x14` |
| 2 | ECX thiscall (client in ECX) | **Falsified** — client is **stack0**; ECX only holds arg3 temp / out LEA |
| 3 | EAX = client host | **Falsified** — call sites load **item*** into EAX (`MOV EAX,EBX` after `RemoveItemByCoid`); client is pushed |
| 4 | Bare `RET` / `RET 4` / `RET 8` | **Falsified** — **`RET 0x14`** (`C2 14 00`) |
| 5 | Walks inventory windows / vtbl refresh | **Falsified** — single `CALL 00402b30` insert-or-find; no window table |
| 6 | Different map than NotifyActiveMissionChanged | **Falsified** — same **client+0xF14** shell (MEGA-040 sealed) |
| 7 | Equal key rewrites payload here | **Falsified** — delegated to `00402b30` hit path (`inserted=0`, no rewrite) |
| 8 | Only callee of RecvInventoryUseItemResponse | **Falsified** — **5** xrefs across 4 parents (tinker/gadget/remove paths) |
| 9 | Product name sealed without `_Inferred` | **Fails** — no demangle; role-from-callers only |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Decisive machine dataflow

```text
; entry EAX = item*, CL = flag, stack = client,1,0,-1,-1
SUB  ESP, 0x38
MOV  [ESP+0x18], EAX          ; value.key = item*
MOV  [ESP+0x20], EAX
MOV  [ESP+0x5], CL
MOV  DL, [ESP+0x40]           ; a1
...
MOV  EAX, [ESP+0x40]          ; reload client (after PUSH EBX)
ADD  EAX, 0xF14               ; map = client+0xF14
LEA  EBX, [ESP+0x24]          ; value* (ESP_sub+0x18)
PUSH out
CALL 0x00402b30               ; EAX=map, EBX=value*, RET 4 callee
POP  ESI / POP EBX
ADD  ESP, 0x38
RET  0x14
```

Call-site (`Client_RecvInventoryUseItemResponse` @ `0x008102de`):

```text
CALL InventoryGrid_RemoveItemByCoid → EBX = item*
CALL FUN_007fee30
PUSH -1; PUSH -1; PUSH 0; PUSH 1; PUSH EBP   ; EBP=client
XOR  CL, CL
MOV  EAX, EBX
CALL 0x00933310
```

A ≡ B on live decompile CF + body hex + xrefs + assembly context.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Single-BB insert wrapper CF | **High** | wrong control model |
| EAX=item* key / stack client / RET 0x14 | **High** | stack smash / wrong port |
| Map client+0xF14 | **High** | wrong shell |
| Callee = dualed isnil31 InsertOrFind | **High** | wrong STL family |
| "Refresh windows" product English | **Tentative** | overclaim UI surface |
| Payload field layout beyond key | **Probable** | map value size/layout |

---

## 4. Naming

| Name | Status |
|---|---|
| `Client_UI_RefreshInventoryWindows_Inferred` | **Accept** (role + mega hint; mechanism documented) |
| `Named_CalleeOf_Client_RecvInventoryUseItemResponse_00933310` | **Reject** (multi-caller; false sole-parent) |
| `FUN_00933310` | Ghidra symbol / twin index only |

---

## 5. Verdict

**accept-with-gaps** — adversarial checks falsify decompiler-ABI / thiscall / window-walk / single-parent claims; sealed facts hold. Product English and full payload/UI mechanism remain open. Terminal **false**.
