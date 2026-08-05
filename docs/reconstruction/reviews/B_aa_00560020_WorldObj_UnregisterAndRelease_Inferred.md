# Review B (skeptical / adversarial): `aa_00560020` WorldObj_UnregisterAndRelease_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00560020` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W29-S) |
| **Counterpart** | `reviews/A_aa_00560020_WorldObj_UnregisterAndRelease_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Same as `ActionManager_UnregisterAndRelease` (`0055df40`) | **Falsified** — different body: this uses `+0x120` list, `+0xc4` extract, pair diff walk; 0055df40 uses `0062a410`/`00628f10` |
| 2 | `unaff_EBX` is undefined / UB | **Falsified** — machine loads extract out-buffer after vcall; residual is decompiler artifact |
| 3 | `006caaa0` is free cdecl 5-arg | **Falsified** — `MOV ECX,[manager+0x138]` thiscall (W27-N) |
| 4 | No stack formal / plain ret | **Falsified** — `ret 4`; object on stack |
| 5 | Always runs pair diff | **Falsified** — gated on extract count ≠ 0 |
| 6 | Product name is retail | **Overstated** — `_Inferred` only; no plate string |
| 7 | Callers never double-release | **Open** — some callers also touch `obj+6` after return; may be separate local ref |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Unregister role / twin of 0055ff20 | **High** | Wrong lifecycle port |
| thiscall + ret 4 | **High** | ABI break |
| Swap-remove list | **High** | Leaked enrollment |
| Pair path optional | **High** | Spurious diff walk |
| Extract buffer layout | **Medium** | Wrong pair free |
| Product English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
SUB ESP,0x14; PUSH EBX/ESI; MOV ESI,ECX
lock 0062d960; extract vtbl+0xC; optional 006cad30+006caaa0
0062a510; ref--; clear +8; maybe destroy; swap-remove; 0055f4c0; RET 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Callers stage manager via `world+0xE4A4` pattern.

---

## 4. Surviving contract for AutoCore

```
// When removing an enrolled world/link object:
WorldObj_UnregisterAndRelease_Inferred(manager, object);
// Preserve: ECX=manager, ret 4, optional pair diff, refcount at +6,
// clear +8, swap-remove +0x120, not ActionManager_0055df40.
```

---

## 5. Verdict

Adversarial pass confirms A CF/ABI; gaps limited to product English, nested helpers, caller double-ref patterns → **accept-with-gaps**.
