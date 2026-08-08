# Review B (skeptical / adversarial): `aa_00402410` StdList_CopyCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402410` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R10-019) |
| **Counterpart** | `reviews/A_aa_00402410_StdList_CopyCtor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Mission/reaction domain helper (`FUN_00955010` only ⇒ domain) | **Falsified as product name** — body is pure STL empty-init + range insert; sole caller does not inject domain into this unit. System tag = shared list; partition seed only. |
| 2 | Same as empty default ctor `004023f0` | **Falsified** — default has no insert; this calls `00404490` after empty init; body 134 B vs 22 B; ABI RET8 vs plain RET |
| 3 | In-place assign / clear-then-fill existing list | **Falsified** — always allocates **new** sentinel via `0040fb90`; does not free prior head; constructs into `dest` |
| 4 | Head at `+0`, size at `+4` | **Falsified** — stores **+4** / **+8**; matches dualed default/destroy pair |
| 5 | Thiscall ECX=this, one stack src, `RET 4` | **Falsified** — `MOV ESI,[EBP+8]`; src at `[EBP+0xC]`; **`RET 0x8`** |
| 6 | Cdecl (caller cleans) | **Falsified** — `C2 08 00` callee cleans 8 bytes |
| 7 | Only allocates empty list (no copy) | **Falsified** — `CALL 00404490` with `[src.begin, src.end)` and dest where |
| 8 | Deep-copies arbitrary struct by memcpy | **Falsified** — insert path walks nodes and calls per-element insert (`004040f0` / buy-node chain), not bulk memcpy |
| 9 | Vector / array element ctor itself | **Falsified** — no DATA xrefs; only direct CALLs from `FUN_00955010` |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher; terminal false) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Empty-init + range-insert copy role | **Confirmed** | Wrong port semantics |
| Stdcall dest/src stack args / RET 8 | **Confirmed** | Stack imbalance |
| Head@+4 size@+8 | **Confirmed** | Corrupt list layout |
| Pair with 0040fb90 / sibling 004023f0 | **Confirmed** | Leak / wrong ctor choice |
| Insert = [begin,end) before dest end | **High** (arg wiring + 00404560 loop) | Off-by-one / empty-src edge |
| Element type `T` | **Low** | Wrong payload size in port |
| Domain = missions only | **Falsified for naming** | Misleading product name |
| Insert chain dual completeness | **Open** | Residual callees |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23 ≡ live decompile 2026-08-05 ≡ clean StdList_CopyCtor_Inferred.cpp

00402431  8B 75 08             MOV ESI, [EBP+0x8]     ; dest
00402436  E8 55 D7 00 00       CALL 0040fb90          ; 0040243b-0xD755 = 0040fb90
0040243b  89 46 04             MOV [ESI+0x4], EAX
0040243e  C7 46 08 00 00 00 00 MOV [ESI+0x8], 0
0040244c  8B 45 0C             MOV EAX, [EBP+0xC]     ; src
0040244f  8B 40 04             MOV EAX, [EAX+0x4]     ; src head
0040245d  8B 00                MOV EAX, [EAX]         ; begin
00402465  8B 56 04             MOV EDX, [ESI+0x4]
0040246b  8B 12                MOV EDX, [EDX]         ; where
00402473  51 50 52 56          PUSH end, begin, where, dest
00402477  E8 14 20 00 00       CALL 00404490
00402483  8B C6                MOV EAX, ESI
00402495  C2 08 00             RET 8
```

`FUN_00404560` loop (callee of insert wrapper; evidence only):

```text
for (; param_3 != param_4; param_3 = *param_3)
  FUN_004040f0(param_2 /*where*/, param_3 + 2 /*value*/);
```

Reject ports that:

- Name this as mission/reaction-only helper.
- Treat as empty default ctor (`004023f0`) without insert.
- Use ECX thiscall / `RET` / `RET 4`.
- Place head at +0 or size at +4.
- Skip sentinel alloc and only link existing nodes.
- Claim runtime Confirmed without Launcher evidence.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail MSVC list object (0xC) copy-construct helper (stdcall 2-arg):
//   dest._Myhead = new sentinel{ next=prev=self };
//   dest._Mysize = 0;
//   insert copies of src elements before dest end;

sealed class StdListCopy
{
    // +0 residual
    public ListNode Myhead; // +4
    public int Mysize;      // +8

    // Not C# ctor shape — retail is free stdcall helper:
    // StdList_CopyCtor_Inferred(dest*, src*) -> dest*
}
```

Port note: implement as `new List<T>(src)` / construct-into-dest with element copy. **Do not** assume ECX thiscall like `StdList_DefaultCtor_Inferred`. Pair teardown with free-head destroy. Element `T` from call-site duals later.

---

## 5. Verdict

**accept-with-gaps** — adversarial probes on domain-only, empty-only, wrong offsets, wrong ABI, assign-in-place, and runtime-confirmed all fail or are rejected; copy role + layout + RET8 survive with documented gaps (`T`, insert-chain dual, runtime).
