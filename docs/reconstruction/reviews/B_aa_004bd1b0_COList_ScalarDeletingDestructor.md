# Review B (skeptical / adversarial): `aa_004bd1b0` COList_ScalarDeletingDestructor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bd1b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004bd1b0_COList_ScalarDeletingDestructor.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This is the full COList destructor body | Body is 30 B and only calls `004bbc70` | **Falsified** — wrapper only; body is W26-J unit |
| 2 | Always frees the object | Delete gated by `flags & 1` | **Falsified** — bit0 optional |
| 3 | `__cdecl` / bare `ret` | Exit is `C2 04 00` | **Falsified** — `ret 4` thiscall stack formal |
| 4 | Returns void | Exit `8B C6` then ret | **Falsified** — returns this in EAX |
| 5 | `operator_delete` never returns (decomp WARNING) | Normal CRT delete returns; path only on flag | **Confirmed artifact** — do not port as noreturn CF on both paths |
| 6 | Direct code callers exist | Xrefs DATA-only from vtbl | **Confirmed** — virtual dispatch only |
| 7 | Class is generic unknown helper | vtbl + COList::Insert + body twin | **Falsified** — COList scalar dtor |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| flags&1 polarity | **High** | Leak or double-free |
| Always call body first | **High** | Skip teardown |
| ret 4 / this return | **High** | ABI mismatch |
| vtbl[0] identity | **High** | Wrong delete path |

---

## 3. Cross-check against raw / bytes

```
raw:   FUN_004bbc70(); if (param_2 & 1) operator_delete; return param_1
bytes: 56 8BF1 E8→004bbc70 F644240801 7409 56 E8→delete 83C404 8BC6 5E C20400
vtbl:  009cb448 = 004bd1b0
twin:  body dual accept W26-J; ctor same vtbl this wave
```

---

## 4. Surviving contract for AutoCore

```csharp
// vtbl[0] scalar deleting
object COList_ScalarDeletingDestructor(COList self, byte flags)
{
    COList_Destructor(self);          // always
    if ((flags & 1) != 0)
        Free(self);                   // operator_delete
    return self;
}
// stdcall cleanup of 4 bytes of stack args (ret 4)
```

**Port traps to reject:**

- Skipping body dtor when free flag is clear.
- Inverting bit0 (free when clear).
- Treating decompiler “does not return” as both-path noreturn.
- Using bare `ret` (must be `ret 4`).

---

## 5. Residual gaps (do not block seal)

1. Runtime / image diff.
2. Product English for fields (owned by ctor/body).

---

## Verdict

**accept** — adversarial review cannot break the scalar-delete ABI/CF contract. Residual is verification depth only.
