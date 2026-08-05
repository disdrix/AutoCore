# Review B (skeptical / adversarial): `aa_00497c80` ListTrackedCtx_ClearDestroyAndReset_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00497c80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-R) |
| **Counterpart** | `reviews/A_aa_00497c80_ListTrackedCtx_ClearDestroyAndReset_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler `while{ if count<1 reset; break on non-null; non-return delete}` is accurate | **Falsified** — after delete, bytes `cmp [esi+0x10],0; jg loop`; all non-null entries destroyed |
| 2 | `FUN_007874b0(0,0)` is a free function with no this | **Falsified** — `lea ecx,[esi+0xB8]` before call; thiscall on grid subobject |
| 3 | This is a complete dtor of the 0xC8 object | **Falsified** — does not free self, parent@+0xC4, or clear global; resets for reuse; callers keep the object |
| 4 | Ghidra `undefined FUN_00497c80(void)` means no this | **Falsified** — `mov esi,ecx`; 6 thiscall-style callers |
| 5 | Scaffold NDRiver name is product | **Falsified** — no string evidence; structural ListTrackedCtx name from W32-P layout match |
| 6 | Count is left non-zero after clear | **Falsified** — loop decrements until `<1` |
| 7 | `FUN_00497900` is optional | **Falsified** — always called for non-null before delete; vector-dtor of embedded array |
| 8 | Flag=1 means "ready/enabled" | **Unresolved** — ctor and clear both set 1; some readers early-out on non-zero |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Clear-destroy-reset role | **High** | Wrong lifecycle port |
| Thiscall + return 1 | **High** | ABI break |
| Loop frees all non-null | **High** | Leaks |
| Grid thiscall +0xB8 | **High** | Wrong free target |
| ListTrackedCtx type link | **High** | Orphan unit |
| Entry product type | **Med** | Wrong dtor pairing |
| Flag English | **Low** | Wrong enable policy |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + callers

```
// Entry: 56 8B F1 ... B0 01 5E C3  (113 B, pad CC)
// ApplyDefaultScalars: mov ecx,[esi+0x100]; call FUN_00497c80
// FUN_004982d0: call clear; then *(this+0xC)=10
// FUN_004982f0: call clear; recompute +4/+8 from parent+0xC4 map scale
// FUN_00498260: call clear; delete +0xB4; FUN_00787510 teardown
// Ctor twin 0x00497920: same +0x10/+0x14/+0xB8 layout
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF skeleton; body hex corrects loop and thiscall.

---

## 4. Surviving contract for AutoCore

```
// Port as ListTrackedCtx method:
ok = ListTrackedCtx_ClearDestroyAndReset(ctx);
// Must: destroy each non-null bank[i], zero bank, zero +4/+8/+0xC,
//       free/zero grid@+0xB8 to 0×0, flag=1, return 1.
// Do not free ctx itself or clear DAT_00b035cc.
// Do not trust decompiler non-return on operator_delete.
// Keep FUN_00497900 before delete for each entry.
// Callers may re-set capacity (+0xC) and dims after return.
```

---

## 5. Verdict

Adversarial pass confirms A on role/ABI/byte-corrected loop/grid thiscall/ctor layout link. Residual product English + flag polarity + entry demangle → **accept-with-gaps**.
