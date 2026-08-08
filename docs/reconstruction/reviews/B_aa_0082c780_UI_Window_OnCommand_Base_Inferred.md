# Review B (skeptical / adversarial): `aa_0082c780` UI_Window_OnCommand_Base_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082c780` |
| **VA** | `0x0082c780` |
| **Canonical name** | `UI_Window_OnCommand_Base_Inferred` |
| **Review date** | `2026-08-05` (R11-027) |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_0082c780_UI_Window_OnCommand_Base_Inferred.md` |
| **System** | UI OnCommand base |
| **Verdict** | **accept-with-gaps** — agree with A |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + `disassemble_function` + callers/xrefs (no `disassemble_bytes`). No Launcher.

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_0082c780` only | Scaffold OK; under-describes sealed role |
| Inventory transfer / grid move / packet handler | **Reject** — no item IDs, slots, C2S opcodes, or bag math |
| `UI_Window_OnCommand_Class8_*` merge with parent `0082f510` | **Reject** — parent has jump table 1..0xd + skill 0xED5; this body has none |
| Always-forward-to-parent OnCommand bubble | **Reject** — forwards to **child** `@+0x2b0`, not parent; 70000 path dismisses |
| Always-dismiss / modal-only | **Reject** — dismiss only when id=70000 and class∈{8,0xb,0xe} |
| `stdcall` / no `this` | **Reject** — ESI=ECX; `RET 8` thiscall form |
| Product English proven (window class name) | **Fails** — DATA slot only; keep `_Inferred` |
| `UI_Window_OnCommand_Base_Inferred` | **Accept** — role-aligned with dualed Class8 "Base_OnCommand"; `_Inferred` honest |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| Decompiler is full truth (no EDI load for dismiss) | **Fails** — `MOV EDI,[ESI+0x2b0]` @ `0082c7d9` before `CALL 0090d400` |
| 70000 path ignores class (any class dismisses) | **Fails** — only JZ for EDI∈{8,0xb,0xe}; other classes fall into forward path even when id=70000 |
| Forward uses parent, not child | **Fails** — ECX loaded from `[ESI+0x2b0]` then `CALL [EDX+0x338]` |
| `param_1[0xac]` is element 0xac of a different unit | **Fails** — asm `+0x2b0` = 0xac×4 dword index |
| Return always full EAX=1/0 | **Partial** — false path `XOR AL,AL` only; true dismiss `MOV AL,1`; forward returns callee EAX. Still bool-like handled flag |
| Sole caller is Class8 | **Fails as sole** — also `FUN_00830aa0` + 4 unnamed CALL + DATA |
| Body does skill cast 0xED5 | **Fails** — no 0xED5 / CastSkill; that is Class8 case 1 only |
| Terminal / runtime Confirmed | **Fails** — Terminal **false**; no Launcher |
| Partition "inventory-transfer" means this is grid logic | **Fails as semantic claim** — partition host labels chain; body is UI OnCommand base |

---

## 3. Cross-check against raw + bytes

```text
EBX = cmdId; EDI = cmdClass; ESI = this
if EBX==0x11170 && EDI in {8,0xb,0xe}:
  EDI=[ESI+0x2b0]; CALL 0090d400; AL=1; RET 8
CALL [vtbl+0xd8]
if AL==0 || [ESI+0x2b0]==0: AL=0; RET 8
ECX=[ESI+0x2b0]; PUSH EBX; PUSH EDI; CALL [child.vtbl+0x338]; RET 8
```

Hex anchors:

- `81 FB 70 11 01 00` → CMP EBX, 0x11170
- `83 FF 08` / `0B` / `0E` → class set
- `FF 90 D8 00 00 00` → CALL [EAX+0xd8]
- `83 BE B0 02 00 00 00` → CMP [ESI+0x2b0],0
- `FF 92 38 03 00 00` → CALL [EDX+0x338]
- `C2 08 00` ×3 → RET 8
- DATA `@00a732a4`: `80 C7 82 00` → VA

Clean must **not** invent inventory packets, Class8 case map, skill cast, parent-bubble, or product demangle.

---

## 4. Agreement with Review A

- ABI + CF + immediates + DATA slot: **agree Confirmed**
- Name with `_Inferred`: **agree**
- Gaps (RTTI, predicate English, helper dual, runtime): **agree open**
- Not inventory grid transfer despite partition label: **agree**

---

## 5. Surviving contract for AutoCore

```csharp
// Base UI OnCommand (native thiscall, RET 8)
uint OnCommandBase(UiWindow self, int cmdClass, int cmdId)
{
    if (cmdId == 70000 && (cmdClass == 8 || cmdClass == 0xb || cmdClass == 0xe))
    {
        // FUN_0090d400(self, self.ChildAt0x2B0) — register ESI/EDI
        DismissSelfAndChild(self, self.ChildAt0x2B0);
        return 1;
    }
    if (self.Predicate_Vtbl0xD8() && self.ChildAt0x2B0 != null)
        return self.ChildAt0x2B0.OnCommand_Vtbl0x338(cmdClass, cmdId);
    return 0;
}
```

**Port note:** pair with dualed Class8 specialization `0x0082f510` (handles class-8 cases then falls back here). Do **not** implement as inventory move. Preserve **70000** class set and child-forward offsets until product labels sealed.

**Verdict:** **accept-with-gaps**
