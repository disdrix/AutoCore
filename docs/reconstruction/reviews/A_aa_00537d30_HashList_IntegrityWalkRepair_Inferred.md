# Review A (reconstruction fidelity): `aa_00537d30` HashList_IntegrityWalkRepair_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00537d30` |
| **VA** | `0x00537d30` |
| **Body** | `0x00537d30`–`0x00537d8e` approx (**`ret`**, no stack args) |
| **Canonical name** | `HashList_IntegrityWalkRepair_Inferred` (Ghidra `FUN_00537d30`; alias `Util_HashListError_Repair`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00537d30_HashList_IntegrityWalkRepair_Inferred.md` |
| **System** | container / hash-list integrity (multi-domain) |
| **Live tools** | Ghidra `decompile_function`, `force_decompile`, `analyze_function_complete`, `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — CF + string High; product name open |

---

## 1. Purpose

**Integrity walk + optional cycle repair** on a singly-linked chain rooted at **`list+0x04`**:

1. If head `*(this+4) == 0` → return.
2. Walk nodes: set **touch mark** `*(node+4) = 1`; advance via **`*(node+0xC)`**.
3. If next is null → clear all marks on chain (second walk), return (**healthy**).
4. If next already has mark `!= 0` (**cycle / re-touch**):
   - Log severity **1**: `"HashListError: Went to node we already touched! Attempting repair!"` @ `0x00a64710` via `FUN_007a4480`.
   - Sever: `*(prev+0xC) = 0`.
   - Clear marks on remaining chain; return.
5. No heap free; no key compares — pure topology check.

Called after CNDHash bucket head-inserts (`FUN_0053c460`/`0053c760` family), free-list unlink (`FUN_004e2ca0`), CompleteObjective path, and **30+** other sites — **unconditional** in those callers (not debug-only).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | `force_decompile` @ `0x00537d30` ≡ raw |
| Complete analysis | **34** xrefs; sole callee `FUN_007a4480` |
| Machine | `read_memory` @ `0x00537d30` length 96 |
| String | `read_memory` @ `0x00a64710` → full HashListError message |
| Consumer dual | `A_aa_004e2ca0_FUN_004e2ca0.md` (always calls this) |
| Insert duals | `A_aa_0053c460_*`, `A_aa_0053c760_*` |
| Raw / clean / function | `raw/aa_00537d30_*`, `reconstructed-exact/FUN_00537d30.cpp` / `Util_HashListError_Repair_00537d30.cpp` |

---

## 3. Authoritative body

```c
void __fastcall FUN_00537d30(int list /* ECX this */)
{
  int cur, prev;

  cur = *(int *)(list + 4);
  if (cur == 0) return;

  do {
    prev = cur;
    *(unsigned char *)(prev + 4) = 1;
    cur = *(int *)(prev + 0xC);
    if (cur == 0) {
      for (cur = *(int *)(list + 4); cur != 0; cur = *(int *)(cur + 0xC))
        *(unsigned char *)(cur + 4) = 0;
      return;
    }
  } while (*(char *)(cur + 4) == 0);

  FUN_007a4480(1, "HashListError: Went to node we already touched! Attempting repair!");
  *(int *)(prev + 0xC) = 0; // sever
  cur = *(int *)(list + 4);
  if (cur != 0) {
    do {
      *(unsigned char *)(cur + 4) = 0;
      cur = *(int *)(cur + 0xC);
    } while (cur != 0);
  }
}
```

---

## 4. Machine seal (`read_memory`)

Hex (start):  
`53 57 8b f9 8b 47 04 33 db 3b c3 74 53 b9 01 00 00 00 56 88 48 04 8b f0 8b 40 0c 3b c3 74 2f 38 58 04 74 ef 68 10 47 a6 00 51 e8 … 89 5e 0c …`

| Claim | Evidence | Conf |
|---|---|---|
| ECX = list (`mov edi,ecx`) | `8b f9` | **High** |
| Head at `+4` | `8b 47 04` | **High** |
| Mark byte `node+4 = 1` | `88 48 04` with `ecx=1` | **High** |
| Next at `node+0xC` | `8b 40 0c` | **High** |
| String imm `0x00a64710` | `68 10 47 a6 00` | **High** |
| Log severity 1 | `51` push ecx after mov ecx,1 path / push 1 | **High** |
| Sever `mov [esi+0xc], ebx` (ebx=0) | `89 5e 0c` | **High** |
| Clear marks second pass | `88 58 04` loop | **High** |
| No `ret N` stack cleanup | plain `ret` / epilogue | **High** |

---

## 5. List / node contract

| Offset | Role |
|---|---|
| `list+0x04` | chain head |
| `node+0x04` | touch mark (byte) |
| `node+0x0C` | next |

Compatible with CNDHash **bucket chain** heads (insert writes head at sentinel `+4`) and free-list objects used by `FUN_004e2ca0`.

---

## 6. Gaps / open

1. Product symbol (util / method of hash).
2. Whether sever drops nodes permanently without free (caller ownership residual).
3. Severity-1 log policy (fatal vs warn) for `FUN_007a4480`.
4. Full enumeration of all 34 callers' list object type.
5. Runtime cycle injection not performed.

---

## 7. Safe claims

| Safe | Unsafe |
|---|---|
| Touch-walk + cycle sever + clear marks | “debug only / optional” |
| Multi-domain integrity helper | Mission-exclusive API |
| accept-with-gaps | complete / bit-exact |
