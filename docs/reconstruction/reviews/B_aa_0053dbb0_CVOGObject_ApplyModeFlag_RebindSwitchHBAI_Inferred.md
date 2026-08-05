# Review B (skeptical / adversarial): `aa_0053dbb0` CVOGObject_ApplyModeFlag_RebindSwitchHBAI_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053dbb0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W26-E) |
| **Counterpart** | `reviews/A_aa_0053dbb0_CVOGObject_ApplyModeFlag_RebindSwitchHBAI_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` (+ analyze complete for xrefs).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is only an AI switch wrapper | **Falsified** — always rebinds; AI switch is conditional tail only |
| 2 | Direct callers are network packet handlers | **Falsified as exclusive** — xrefs are **vtable slots**; network may call via vtable but no direct FUN xref |
| 3 | Always SwitchHBAI | **Falsified** — skipped when `obj+0x40!=0 && obj+8!=0` |
| 4 | Flag==0 → AI code 6 | **Falsified** — flag==0 → **1**; flag≠0 → **6** |
| 5 | `param_1[2]` is manager | **Falsified** — passed to `FUN_00560e90` as **world object** (same formal as RebindActivate's object) |
| 6 | Returns HRESULT / status | **Falsified** — void; plain `ret 4` or tail into SwitchHBAI |
| 7 | Child loop uses fixed count from first +0x4c only | **Partially true residual** — first +0x4c gates entry (`!=0`); loop re-reads +0x4c each iter for bound |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Rebind + optional AI CF | **High** | Ghost/AI desync on mode apply |
| Tail codes 1/6 | **High** | Wrong HBAI family |
| Virtual dispatch | **High** | Miss subclass coverage |
| Mode flag product English | Medium | Naming only |
| Lock helper semantics | Medium residual | Threading edge cases |
| Child notify(4) meaning | Medium | Incomplete child state |

---

## 3. Cross-check against raw + bytes

```
mov esi, ecx
cmp dword [esi+8], 0
jz ret
mov bl, [esp+0x10]     ; modeFlag after 3 pushes
test bl, bl
jz  path_vtbl_10
call [eax+0x0C]
mov ecx, [esi+8]
mov dword [ecx+0x28], 0x10
; … child walk …
call FUN_00560e90
; … dual AI notify …
; if needsSwitch:
pop edi; pop esi; pop ebx
mov dword [esp+4], 1 or 6
jmp FUN_005d4440
; else:
pop edi; pop esi; pop ebx
ret 4
```

Clean must **not** invent packet decode, inventory, or drive physics here.

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape (virtual on CVOGObject)
void ApplyModeFlag_RebindSwitchHBAI(CVOGObject self, byte modeFlag)
{
    var wo = self.WorldHostAtPlus8;
    if (wo == null) return;

    if (modeFlag == 0)
        self.Vtbl0x10();
    else {
        self.Vtbl0x0C();
        wo.ModeStampAt0x28 = 0x10;
        NotifyChildren(self.ChildListAt0x0C, arg: 4);
    }

    WorldObj_RebindActivate(wo, staged: 1);
    LockedAiNotify(wo.AiHostAt0x3C, DAT_00b04610); // +0x50 then +0x54

    bool needsSwitch = (wo.FlagAt0x40 == 0) || (wo.PtrAt8 == null);
    if (needsSwitch)
        CVOGObject_SwitchHBAIByCode(self, modeFlag == 0 ? 1 : 6);
}
```

---

## 5. Open questions

1. Subclass set for the 8 vtable installs.
2. Whether server NPC mode apply needs identical 1/6 AI pairing.
3. Interaction with soft-not-ready / phys recreate that also calls RebindActivate.

**Verdict:** **accept**
