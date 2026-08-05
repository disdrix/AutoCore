# Review B (skeptical / adversarial): `aa_00431430` StdVector_UninitializedCopy_BasicString

| Field | Value |
|---|---|
| **Stable ID** | `aa_00431430` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-H) |
| **Counterpart** | `reviews/A_aa_00431430_StdVector_UninitializedCopy_BasicString.md` |
| **Scratch** | `docs/reconstruction/tmp/a_00431430.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Pure void / no return | **Falsified** — insert uses `uVar3 = FUN_00431430(...)`; EAX unclobbered |
| 2 | Does the string ctor loop itself | **Falsified** — only calls `FUN_0046a2c0`; 32 B body |
| 3 | Assign/move-assign fill (like `FUN_00431450`) | **Falsified** — sibling is assign; this is Ucopy path |
| 4 | `RET 4` / two stack args | **Falsified** — `C2 0C 00` three stack + ECX |
| 5 | Memcpy / POD relocate | **Falsified** — callee uses `basic_string` copy ctor under SEH |
| 6 | Scaffold `Named_CalleeOf_Named_*` | **Reject** — structural Ucopy name preferred |
| 7 | Grow-path only helper | **Falsified** — in-place arms only; grow calls `FUN_0046a2c0` directly |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Thin rebind shape | **High** | Wrong ownership of string loop |
| ABI RET 0x0C + thiscall | **High** | Stack corruption |
| EAX return | **High** | Lost end pointer on mid-shift |
| Product demangle | **Low** | Naming only |
| 5-arg residual | **Med** | Port may drop unused extras |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// insert in-place (W32-B decompile):
//   FUN_00431430(where, end, where + count*0x1c);           // shift tail right
//   uVar3 = FUN_00431430(end - count, end, end); end = uVar3; // open hole at end
// grow path skips this wrapper and calls FUN_0046a2c0 directly.
```

Live decompile ≡ forward. Bytes seal RET/cleanup. Closes W32-B residual nested `FUN_00431430`.

---

## 4. Surviving contract for AutoCore

```
// Port as thiscall Ucopy rebind:
string* Ucopy(vector<string>* /*vec*/, string* first, string* last, string* dest) {
  // placement copy-construct [first,last) into dest; return dest + distance
  // Retail forwards through FUN_0046a2c0 with optional this/dest extras.
}
// RET 0x0C. Do not confuse with assign-fill FUN_00431450 or destroy-range FUN_00431aa0.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/return/role. Residual product demangle + nested core → **accept-with-gaps**.
