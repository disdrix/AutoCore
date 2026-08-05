# Review B (skeptical / adversarial): `aa_00944d50` Client_ClearObjectReferences

| Field | Value |
|---|---|
| **Stable ID** | `aa_00944d50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00944d50_Client_ClearObjectReferences.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same as CompletelyDestroyObject | CompletelyDestroyObject is `0x009440e0` with refuse-local-character + format string; this unit has different CF and 3 call sites | **Falsified** — **distinct** |
| 2 | `__cdecl` multi-arg | Entry ECX→EBX; `RET 4` | **Falsified** — **`__thiscall(client, obj)`** |
| 3 | Always destroys the object | No virtual dtor of `obj`; only clears refs / UI | **Falsified** — **reference scrub only** |
| 4 | Always refreshes mission UI | Gated on inventory/equip membership; else goto skip | **Confirmed gate** |
| 5 | Name is product-string sealed | No strings in unit | **Admit** — **Probable/inferred** |
| 6 | Tree walk is trivial | Lower-bound by COID + erase + re-walk; decompiler SSA noisy | **Confirmed complex** — raw is authority |
| 7 | Only inventory system | Touches select chrome, selection list, global dialog, mission UI, sticky slot | **Falsified exclusive** — **multi-system** |
| 8 | Callers include CompletelyDestroyObject | xrefs: Respawn_dtor, FUN_009791c0, FUN_009788b0 only | **Confirmed limited callers** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI thiscall + RET 4 | **High** | Stack corruption |
| Null early-out | **High** | Crash on null |
| Stage order of major branches | **High** | Missed UI leak |
| Sticky `+0x3bf8` / select panels | **High** | Dangling UI ptr |
| COID tree erase correctness bit-exact | **Medium** | decompiler iterator noise |
| Inventory/mission gate boolean | **High** | Spurious UI refresh |
| Product names of panels | **Low** | Docs only |
| FUN_00996ff0 meaning | **Low** | Unknown side system |

---

## 3. Cross-check against raw + bytes

```
entry @ 00944d50:
  51 53 55              push ecx, ebx, ebp
  8B 6C 24 10           mov ebp, [esp+10h]   ; obj
  85 ED                 test ebp, ebp
  8B D9                 mov ebx, ecx         ; client
  0F 84 01 06 00 00     je  early_ret        ; null → far forward
  39 AB F8 3B 00 00     cmp [ebx+0x3bf8], ebp
  …
epilogue:
  … C2 04 00            ret 4
```

Callee set includes sealed siblings (`Object_SetSelectedTarget`, `InventoryGrid_ContainsItem`, `Vehicle_HasEquippedTFID`, `UiSelectWidget_ApplySelectChrome`, `Client_RefreshOpenMissionUiWindows`, `Client_UI_InventorySheet_RemoveByItem`) — consistent with multi-system scrub.

---

## 4. Surviving contract for AutoCore

```csharp
// Client-only. Server destroy already removes authority state; this is UI/client bookkeeping.
void ClearObjectReferences(Client client, GameObject? obj)
{
    if (obj is null) return;

    if (client.StickyObject == obj) client.StickyObject = null;

    // Optional: related-object notify (gfx host flag)
    // COID-keyed map erase
    // Select chrome clear if widget.Selected == obj
    // Inventory membership → unstamp + mission window refresh
    // Open inventory sheets → RemoveByItem if contains
    // Selection list → SetSelectedTarget(null) when points at obj
    // Global dialog invalidate if bound to obj
    // NotifyCoid(obj.Coid)  // FUN_00996ff0
}
```

- Do **not** replace CompletelyDestroyObject with this unit.
- Do **not** omit mission-refresh gate (membership checks).
- Server ports: mostly N/A unless building a full client UI sim.

---

## 5. Residual attacks that stand

1. Product method name unsealed.
2. COID tree node layout / iterator bit-exact not fully re-typed.
3. Several FUN_* callees still unnamed.
4. No runtime hit validation.
5. Named clean plate normalizes tree SSA — bit-exact ports must use raw/alias clean.

None overturn the sealed ABI or stage skeleton. **Verdict: accept-with-gaps**
