# Review B (skeptical / adversarial): `aa_00837d50` UiSelectWidget_ApplySelectChrome_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00837d50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00837d50_UiSelectWidget_ApplySelectChrome_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Clean `__thiscall` ECX this | Body uses **ESI**; callers load ESI | **Falsified** as ECX-thiscall |
| 2 | Decompiler `param_1` is stack formal | Callers pass only EAX/ESI; no push before CALL | **Falsified** as required formal |
| 3 | Sends select-target packet | No send / bitstream | **Falsified** |
| 4 | Always applies child float | Needs `+0x53c` and `+0x518 != 0` | **Falsified** as unconditional |
| 5 | Returns via normal `ret` | Tail **`jmp [vtbl+0x34c]`** | **Falsified** as local ret |
| 6 | Same as panel refresh `00893580` | This is shared helper only | **Do not merge units** |
| 7 | `+0x518` is TFID | Dword from EBX select flag, not dual COID pair | **Do not seal as TFID** |

---

## 2. Live ≡ raw

Live `decompile_function(0x00837d50)` matches raw scaffold control flow (store `+0x518`, vtbl `+0xd0/+0xcc/+0x444/+0xcc`, optional child, `+0x34c`). Assembly corrects register ABI.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI/EAX ABI | **High** | Wrong widget state |
| Chrome vtbl sequence | **High** | Broken select UI |
| Child float optional | **High** | Spurious child updates |
| Product names | **Open** | Doc only |
| Server impact | **None** | N/A |

---

## 4. Surviving contract

```
// ESI=widget*, EAX=select/state
// [widget+0x518]=EAX
// vtbl+0xd0 → byte; vtbl+0xcc(1); vtbl+0x444(); vtbl+0xcc(byte)
// if child(+0x53c) && +0x518: child get/set float (+0x3c8/+0x3b0)
// tail vtbl+0x34c
```

**Verdict:** Adversarial checks clear packet/thiscall overclaim. **accept-with-gaps.**
