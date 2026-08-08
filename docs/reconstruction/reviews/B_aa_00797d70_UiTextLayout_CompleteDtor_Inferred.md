# Review B (skeptical / adversarial): `aa_00797d70` UiTextLayout_CompleteDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00797d70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9L-F) |
| **Counterpart** | `reviews/A_aa_00797d70_UiTextLayout_CompleteDtor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is CNDUIWindow complete dtor | **Falsified** — no vtbl install; stack arg; CNDUIWindow *calls* this on owned `+0x28C` then deletes |
| 2 | This is gfxUIWindow complete dtor | **Falsified** — different VA/ABI; gfx is thiscall `0x00759de0` |
| 3 | thiscall ECX this | **Falsified** — `MOV ESI,[ESP+0x18]`; `RET 4` |
| 4 | Frees host heap | **Falsified** — no `operator_delete(obj)` of self; callers free after return |
| 5 | `operator_delete` noreturn truncates body | **Falsified** — continues `FUN_004271c0` + `~basic_string` + `RET 4` |
| 6 | Scaffold name (callee of VOG_DEBUG_STOP only) | **Falsified as product** — ownership is text-layout block free; debug string is parent path, not this body |
| 7 | cdecl 0-arg / void junk | **Falsified** — one stack arg consumed (`RET 4`) |
| 8 | Same as finalize-only `FUN_00797530` | **Falsified** — finalize is a callee; this also frees vectors + string |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Complete vs free-host | **High** | Double-free |
| ABI stack + RET 4 | **High** | Stack corruption |
| Offset map | **High** | Wrong field teardown |
| Product demangle | **Open** | Name residual only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
// FUN_00797d70:
// SEH; ESI = stack arg
addss [ESI+0xA4], [ESI+0xA8]; zero +0xA8
mov ebx, esi; push 1; call FUN_00797530
delete [ESI+0x94]; null triple
lea ebx, [ESI+0x80]; call FUN_004271c0
lea ecx, [ESI+0xC]; call ~wstring
ret 4
```

Live decompile 2026-08-05 ≡ raw CF; epilogue hex seals `RET 4`.  
Caller pattern from `CNDUIWindow_CompleteDtor`: `FUN_00797d70(p); operator_delete(p);`.

---

## 4. Surviving contract for AutoCore

```
// Port complete dtor of owned layout block only:
void UiTextLayout_CompleteDtor_Inferred(void* layout) {
  // merge metrics; finalize; free vectors; ~wstring
}
// Caller:
//   UiTextLayout_CompleteDtor_Inferred(p);
//   operator_delete(p);
// Do NOT free layout inside this function.
```

---

## 5. Verdict

**accept-with-gaps** — adversarial claims against role/ABI/host-free are falsified. Product English remains open → `_Inferred` retained.
