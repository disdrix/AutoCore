# Review B (skeptical / adversarial): `aa_005bbb90` FUN_005bbb90

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bbb90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005bbb90_FUN_005bbb90.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Only stores flag | Activate writes `+0x804/810/808`; deactivate may clear list children | **Falsified store-only** |
| 2 | Deactivate always clears list | Needs float threshold + mode!=4 + `param_3==0` | **Confirmed heavily gated** |
| 3 | `param_3` unused | Gates deactivate clear | **Falsified** — **material** |
| 4 | `cdecl` / no stack cleanup | `C2 08 00` | **Falsified** — **stdcall/thiscall ret 8** |
| 5 | Same object layout as FX host | Offsets in 0x7xx–0xAxx — different host type | **Confirmed different object** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI thiscall + 2 chars + ret 8 | **High** | Stack corruption |
| `+0x7F8` flag store | **High** | Stuck active state |
| Activate field writes | **High** | Timer/state desync |
| Deactivate multi-gate | **High** | Spurious clears / missed clears |
| Product field names | **Low** | Port naming only |

---

## 3. Cross-check against raw + bytes

```
raw CF matches live decompile.
entry: 8A442404 84C0 8881F8070000 742F ... C20800
deactivate: comiss vs DAT_00aaa66c; cmp [*(this+4)+0x28],4; cmp [esp+8],0
list head 0xA24, clear payload +0x16c/+0x170

≡ sealed. Chain parent: 004b8dc0 walks host+0x1E0 → this unit.
```

---

## 4. Surviving contract for AutoCore

```csharp
void Object_OnFxHostActive(Obj o, bool on, bool suppressChildClear = false)
{
    o.ActiveMirror /*+0x7F8*/ = on;
    if (on)
    {
        o.Field_804 = 0;
        o.Field_810 = o.Field_8FC;
        if ((o.Flags_989 & 0x10) != 0)
            o.Field_808 = o.Field_900;
        return;
    }
    if (o.Field_900 >= Threshold_aaa66c
        && o.ModeFromParent /**(+4)+0x28*/ != 4
        && !suppressChildClear)
    {
        foreach (var c in o.List_A24)
        {
            c.Payload.Field_16C = 0;
            c.Payload.Field_170 = 0;
        }
    }
}
```

---

## 5. Open questions

1. Product object class name.
2. Threshold / mode-4 product meaning.
3. Runtime verification.

**Verdict:** **accept**
