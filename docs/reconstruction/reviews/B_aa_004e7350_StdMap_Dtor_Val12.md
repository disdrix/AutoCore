# Review B (skeptical / adversarial): `aa_004e7350` StdMap_Dtor_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e7350` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W29-M) |
| **Counterpart** | `reviews/A_aa_004e7350_StdMap_Dtor_Val12.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus meta/xrefs; no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Function ends at `operator_delete` (decomp noreturn) | **Falsified** — bytes continue: null head/size + `C3` |
| 2 | Ghidra body end `0x004e736f` is complete | **Falsified** — exclusive end is `0x004e737e` (46 B) |
| 3 | Clears only size, keeps head sentinel | **Falsified** — deletes head then nulls both head and size |
| 4 | `__stdcall` / has stack args | **Falsified** — thiscall, `C3` ret 0 |
| 5 | Product-specific VOG_DEBUG logic | **Falsified** — pure map dtor; parent `004d64d0` owns product teardown |
| 6 | isnil@+0x15 erase twin | **Falsified** — uses Val12 erase-range `004e5120` (isnil@+0x19) |
| 7 | Single caller | **Falsified** — two xrefs from same parent (two maps) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Clear-all + free head CF | **High** | leak / double-free |
| Post-delete nulls | **High** | dangling head use |
| ABI `RET 0` thiscall | **High** | stack smash if treated as stdcall |
| Erase-range callee identity | **High** | wrong node free path |
| Product map type | **Tentative** | docs only |
| Runtime capture | **Open** | matrix policy |

---

## 3. Cross-check against raw + bytes

```
this = map (ECX/ESI); head = *(this+4)
EraseRange(this, &tmp, *head, head)   // FUN_004e5120 @ 004e7362
operator_delete(head); add esp,4
*(this+4)=0; *(this+8)=0
pop esi; pop ecx; ret   // C3
```

Scaffold raw decompile truncated after delete (false noreturn). W29-M append seals epilogue from `read_memory`. Clean documents full CF.

---

## 4. Surviving contract for AutoCore

```
// Val12 map destructor body — not a partial clear helper
StdMap_Dtor_Val12(map):
  EraseRange_Val12(map, begin=*head, end=head)  // free value nodes + reset links
  operator_delete(head)                           // free sentinel
  head = nullptr; size = 0

// Do not use isnil@+0x15 erase-range (004bacf0) here.
// Do not stop at operator_delete — null stores are required.
```

---

## 5. Open questions

1. Exact product types of the two maps destroyed by `FUN_004d64d0`.
2. Empty-map path behavior of erase-range (owned by W28-P).
3. Runtime / differential.

**Verdict:** **accept-with-gaps**
