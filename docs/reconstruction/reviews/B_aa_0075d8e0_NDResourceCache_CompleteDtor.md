# Review B (skeptical / adversarial): `aa_0075d8e0` NDResourceCache_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075d8e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W35-I) |
| **Counterpart** | `reviews/A_aa_0075d8e0_NDResourceCache_CompleteDtor.md` |
| **Scratch** | `tmp/a_0075d8e0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler body is complete | **Falsified** — bytes continue past both `operator_delete` “noreturn” sites through `DAT_00d1f050=0` + `RET 4` |
| 2 | Ghidra function end `0x0075d955` is authoritative | **Falsified** — end mid-instruction stream; true end `0x0075d9BF` exclusive (223 B) |
| 3 | ECX-thiscall dtor | **Falsified** — stack load to EBP; `RET 4` |
| 4 | Frees the host object | **Falsified** — no `operator_delete(self)`; only nested blocks / preloader |
| 5 | Leaves `DAT_00d1f050` live | **Falsified** — `MOV [0x00d1f050], EBX` with EBX=0 |
| 6 | Unrelated to Palantir | **Falsified** — sole product caller is `Palantir_CompleteDtor` with `self+0x30`; SEH unwind siblings |
| 7 | AssPreloader path is speculative | **Falsified** — `FUN_00971050` logs `assPreloader.cpp` / “Preloaded asset…”; ctor EnsureAssPreloader writes `+0x6c` |
| 8 | Nested callees dual-sealed here | **Accepted gap** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stack-self + RET 4 + no free self | **High** | double-free / leak |
| Full stage order (223 B) | **High** | UAF mid-dtor |
| `DAT_00d1f050` clear | **High** | stale cache singleton |
| Host at Palantir+0x30 | **High** | wrong embed offset |
| Product English NDResourceCache vs AssManager | **Med** | naming only |
| Nested callee internals | **Low** | incomplete port of children |
| Runtime | **Open** | matrix |

---

## 3. Cross-check against ctor + parent dtor

```
// FUN_0075d470 (ctor, unowned)          // FUN_0075d8e0 (this dual)
DAT_00d1f050 = self                      DAT_00d1f050 = 0
NestedHash_Ctor(self)                    FUN_0075d6f0 NestedHash teardown
InitializeCriticalSection(self+0x3c)     DeleteCriticalSection(self+0x3c)
tree head @ +0x5c                        erase tree + free head
+0x6c = 0; EnsureAssPreloader            destroy + free AssPreloader; +0x6c=0

// Palantir_CompleteDtor (W34-K)
FUN_0075d8e0(self+0x30)   // stack push; matches RET 4 callee
```

Ctor/dtor symmetry on `+0x3c` / `+0x58` / `+0x6c` / global is strong evidence this is the complete dtor of the `FUN_0075d470` host — not a partial helper.

---

## 4. Surviving contract for AutoCore

```
// Port as complete dtor of cache host (embedded or freestanding):
void NDResourceCache_CompleteDtor(Host* self /*stack; RET 4*/) {
  NestedHash_TeardownEntries(self);          // FUN_0075d6f0
  if (auto* pre = self->preloader /*+0x6c*/) {
    AssPreloader_RetireNeverLoaded(pre);     // FUN_00971050
    AssPreloader_Dtor(pre);                  // FUN_00971180
    operator_delete(pre);
    self->preloader = nullptr;
  }
  StdTree_EraseAll_AndFreeHead(self+0x58);
  DeleteCriticalSection(self+0x3c);
  self->flag_0x54 = 0;
  OwnedPtrTable_Clear(self+0x28);
  // free optional +0x14 block; null +0x14..+0x1C
  ListShell_Tidy(self+0x04);
  DAT_00d1f050 = nullptr;
}
// Do not free self here (Palantir embeds at +0x30).
// Do not trust Ghidra/decompiler truncated body.
```

---

## 5. Verdict

Adversarial checks confirm stack ABI, full byte body beyond Ghidra end, global clear, and Palantir embed; nested plates remain open → **accept-with-gaps**.
