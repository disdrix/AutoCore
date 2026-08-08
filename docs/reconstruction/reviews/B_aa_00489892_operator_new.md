# Review B (skeptical / adversarial): `operator_new` @ `0x00489892`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00489892` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Wave** | R10-002 |
| **Counterpart** | `reviews/A_aa_00489892_operator_new.md` |
| **Verdict** | **accept** as CRT IAT thunk; **reject** treating as game-owned allocator policy |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Custom AutoAssault heap manager / freelist | **Falsified** — 6-byte `JMP [IAT]`; PE import `operator_new` |
| 2 | Body implements size checks / alignment / pooling | **Falsified** — no local instructions beyond JMP |
| 3 | Decompiler “recursive operator_new” is real recursion | **Falsified** — decompiler artifact for IAT JMP |
| 4 | Name needs `_Inferred` product invent | **Falsified** — Confirmed CRT symbol |
| 5 | Stable ID / clean may be `aa_00685b20` | **Falsified for this unit** — OWN VA is `0x00489892`; `0x00685b20` is a separate 1-xref thunk |
| 6 | `__stdcall` / thiscall | **Falsified** — `__cdecl` prototype + caller stack cleanup pattern |
| 7 | Returns always non-null | **Open / not sealed here** — CRT may throw; unit does not handle OOM |
| 8 | inventory-transfer exclusive logic | **Falsified** — universal CRT; parent dual only situates residual wave |
| 9 | Safe to reimplement with different failure policy in AutoCore game code | **Survives as policy risk** — must match call-site assumptions (often null-deref on OOM) |
| 10 | Clean invents multi-line body | **Falsified** — models single IAT call |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Byte-level thunk CF | **Confirmed** | Low |
| Library identity | **Confirmed** | Mis-port as game allocator wastes effort |
| CRT OOM / throw semantics | **Medium** | Call sites often assume success |
| IAT mutability at runtime | **High** (slot exists) | Hooks could redirect |
| Conflation with `operator_new[]` @ `0x00489834` | **Must keep separate** | Array vs scalar new |

---

## 3. Surviving contract

```c
// MSVC C++ scalar new — IAT trampoline, not game domain
// 00489892: FF 25 64 66 9C 00
void * __cdecl operator_new(unsigned int size_bytes) {
  return (*PTR_operator_new_009c6664)(size_bytes);
}
// siblings: operator_new[] @ 0x00489834; operator_delete @ 0x00489822
```

**Port note for AutoCore:** do **not** invent a game-specific `operator_new` at this VA. Server/client ports use host language `new` / pooled allocators at **call sites** with explicit sizes already dualed (`0x30` tree nodes, `0xC` list nodes, InventoryGrid sizes, etc.).

**Verdict:** **accept** sealed IAT thunk; exclude from game-logic port priority; keep name `operator_new` without `_Inferred`.
