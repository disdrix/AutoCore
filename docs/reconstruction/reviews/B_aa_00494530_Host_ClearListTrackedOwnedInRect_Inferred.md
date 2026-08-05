# Review B (skeptical / adversarial): `aa_00494530` Host_ClearListTrackedOwnedInRect_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00494530` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-D) |
| **Counterpart** | `reviews/A_aa_00494530_Host_ClearListTrackedOwnedInRect_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `operator_delete` is noreturn; zero never runs | **Falsified** — body hex continues to `mov [elem+0x24],0` and loop/`C3` after delete |
| 2 | `FUN_004be2a0` is not thiscall / no ECX | **Falsified** — bytes `mov ecx, owned` before call |
| 3 | Function takes the two stack args of the wrapper | **Falsified** — body bare `C3`, no stack formals; wrapper alone does `ret 8` |
| 4 | ECX is map/ctx not host | **Falsified** — uses `+4/+0x28/+0x64..+0x70` host layout; wrapper reloads ECX from `+0xE898` |
| 5 | Zero only when owned non-null | **Falsified** — zero is after the `if`, on both paths |
| 6 | Element stride is not 0x28 | **Falsified** — `lea` scale `index*5*8` = `*0x28`; matches W29-F/W30-Q host grid |
| 7 | No callers | **Falsified** — code call from `0x0094ecec` (wrapper `0x0094ece0`); DATA from `FUN_00959230` |
| 8 | Also frees the elem array | **Falsified** — only owned@+0x24; arr pointer unchanged |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Rect clearer role | **High** | Wrong port unit |
| Owned dtor identity (`004be2a0`) | **High** | Leak / double-free |
| Always-null slot | **High** | Dangling owned |
| Wrapper host load | **High** | Wrong this |
| Product field English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// W30-P ListTrackedObj_CompleteDtor callers include this VA.
// W29-F Elem0x28_CompleteDtor: same owned@+0x24 pattern on element teardown.

// Wrapper 0x0094ece0:
mov eax, [ecx+0xE04]
mov ecx, [eax+0xE898]
call FUN_00494530
mov eax, 1
ret 8
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Full-body hex seals post-delete zero.

---

## 4. Surviving contract for AutoCore

```
// Port as host rect owned-clear only:
void Host_ClearListTrackedOwnedInRect(void* host) {
  // for x in [host+0x64, host+0x6C), y in [host+0x68, host+0x70):
  //   owned = arr[index].ptr@+0x24; if owned: complete_dtor; delete; always null
}
// Do not free arr@+0x28 here.
// Ignore Ghidra noreturn on operator_delete.
// Wrapper supplies host from nested +0xE898; method itself is host-ECX.
```

---

## 5. Verdict

Adversarial pass confirms A on role/ABI/rect/owned teardown. Residual product English → **accept-with-gaps**.
