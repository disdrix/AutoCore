# Review B (skeptical / adversarial): `aa_00964d00` PalantirSub10_DestroyOwnedPtrVecAndComUninit

| Field | Value |
|---|---|
| **Stable ID** | `aa_00964d00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W35-J) |
| **Counterpart** | `reviews/A_aa_00964d00_PalantirSub10_DestroyOwnedPtrVecAndComUninit.md` |
| **Scratch** | `tmp/a_00964d00.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is ECX-thiscall | **Falsified** — `MOV ESI,[ESP+…]`; no ECX self; **`RET 4`** |
| 2 | cdecl (caller cleans) as W34-K stated | **Falsified** — `C2 04 00` callee cleans |
| 3 | Free buffer only when begin is null | **Falsified** — free when **non-null**; decompiler inverted |
| 4 | Zero/Release/CoUninit only on null-begin branch | **Falsified** — always executed after free path |
| 5 | `operator_delete` never returns | **Falsified** — false Ghidra noreturn; loop continues |
| 6 | Frees the subobject itself | **Falsified** — embedded nest; no free of `self` |
| 7 | Element type fully sealed here | **Accepted gap** — only `FUN_00735390` + delete |
| 8 | Not part of Palantir | **Falsified** — complete dtor + SEH push `host+0x10` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| stdcall stack self / RET 4 | **High** | stack imbalance |
| Owned-ptr vector destroy | **High** | leak / double-free |
| COM Release + CoUninitialize | **High** | COM apartment leak / UAF |
| Element product plate | **Low** | wrong element dtor port |
| +0x00 field | **Open** | layout hole |
| Runtime | **Open** | matrix |

---

## 3. Cross-check against raw + bytes + callers

```
// FUN_00964d00 (bytes)
ESI = stack self
loop [begin,end): FUN_00735390(*it); delete *it
if begin: delete begin
triad=0; Release(com); com=0; CoUninitialize(); triad=0
RET 4

// Caller FUN_00754320
ADD ESI, 0x10
PUSH ESI
CALL 0x00964d00

// SEH Unwind sites
host = [EBP-0x10] or [EBP+4]
PUSH host+0x10
CALL 0x00964d00
```

IAT at call site resolves to `CoUninitialize` (`PTR_CoUninitialize_009c697c`).

---

## 4. Surviving contract for AutoCore

```
// Port as stdcall nested tidy (not thiscall, not free-self):
void PalantirSub10_DestroyOwnedPtrVecAndComUninit(PalantirSub10* self) {
  for (void** it = self->begin; it != self->end; ++it)
    if (*it) { Element_CompleteDtor(*it); operator_delete(*it); }
  if (self->begin) operator_delete(self->begin);
  self->begin = self->end = self->capEnd = nullptr;
  if (self->com) self->com->Release();
  self->com = nullptr;
  CoUninitialize();
  self->begin = self->end = self->capEnd = nullptr;
}
// Do not treat as cdecl.
// Do not skip CoUninitialize or COM Release.
// Element_CompleteDtor remains residual (FUN_00735390).
```

---

## 5. Verdict

Adversarial pass confirms A on ABI and teardown order; element product dual remains open → **accept-with-gaps**.
