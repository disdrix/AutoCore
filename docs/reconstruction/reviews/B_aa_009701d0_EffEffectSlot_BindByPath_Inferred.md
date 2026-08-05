# Review B (skeptical / adversarial): `aa_009701d0` EffEffectSlot_BindByPath_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009701d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (W37-Q) |
| **Counterpart** | `reviews/A_aa_009701d0_EffEffectSlot_BindByPath_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + function metadata (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | cdecl / multi-arg stack only | **Falsified** — ECX is slot (`mov edi,ecx`); **`ret 4`** |
| 2 | Returns effect pointer on success | **Falsified** — success loads stack formal; callers check `-1 < status` |
| 3 | Always leaks old slot | **Falsified** — old path dec ref + vtbl+8 on zero |
| 4 | No first-ref side effect | **Falsified** — vtbl+4 when refcount becomes 1 |
| 5 | Same as `FUN_0096fff0` set-param | **Falsified** — different callee set; this is load+bind |
| 6 | Debug path always runs | **Falsified** — gated by `DAT_00d1f050+0x68` |
| 7 | Scaffold void return is dual-ready | **Falsified** — Ghidra signature incomplete; status + `ret 4` required |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Fail `-1` / success status | **High** | caller OR-accumulate FX init wrong |
| Refcount swap order (add new before release old) | **High** | premature free if same object rebound |
| ABI `ret 4` | **High** | stack smash |
| Product English | Medium | naming only |
| Loader name semantics | Medium | port path domain |

---

## 3. Cross-check against raw + bytes

```
effect = Load(DAT_00d1f61c, path, &status)
if !effect: return -1
AddRef(effect); if first: vtbl+4
if old: Release(old)  // dec; vtbl+8 on 0
*slot = effect
if debug_gate: notify
return status
ret 4
```

Clean must **not** return effect*, skip first-ref vtbl+4, or use cdecl without ECX slot.

Note: if rebound to the **same** object, AddRef then Release nets zero change but still calls first-ref only when going 0→1 (not an issue if already held). Adversarial residual: self-assign edge not specially optimized (retail does full path).

---

## 4. Surviving contract for AutoCore

```csharp
// Load effect by path/token; swap into slot with intrusive refcount.
int BindEffectSlot(ref Effect? slot, PathToken path)
{
    var (effect, status) = EffectManager.Load(path);
    if (effect is null) return -1;
    effect.AddRef(); // first → Activate()
    slot?.Release();
    slot = effect;
    return status; // >= 0
}
```

Server ports that return the object pointer, use `IDisposable` without matching first-activate, or treat `-1` as success will diverge from client FX bootstrap OR-accumulators.
