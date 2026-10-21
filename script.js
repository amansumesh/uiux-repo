const $ = (s) => document.querySelector(s);
const loginScreen = $('#loginScreen');
const portal = $('#portal');
const content = $('#pageContent');
let currentPage = 'home';
let currentStudent = 'Aman Sumesh';

const icons = {
  assignment: '<svg viewBox="0 0 24 24"><rect x="5" y="3" width="14" height="18" rx="2"/><path d="M9 3V2h6v1M8 8h8M8 12h8M8 16h5"/></svg>',
  warning: '<svg viewBox="0 0 24 24"><path d="m12 3 10 18H2z"/><path d="M12 9v5m0 3v.1"/></svg>',
  calendar: '<svg viewBox="0 0 24 24"><rect x="3" y="5" width="18" height="16" rx="2"/><path d="M16 3v4M8 3v4M3 10h18"/></svg>'
};

function toast(s) {
  const t = $('#toast');
  t.textContent = s;
  t.style.display = 'block';
  clearTimeout(window.toastTimer);
  window.toastTimer = setTimeout(() => {
    t.style.display = 'none';
  }, 3000);
}

function heading(title, desc) {
  return `
    <div class="content-top">
      <div>
        <h1 class="page-heading">${title}</h1>
        <p class="page-description">${desc}</p>
      </div>
      <div class="date-label">Academic Portal&nbsp; · &nbsp;2026</div>
    </div>
  `;
}

function attendance(score, classes, total, good, title, code) {
  return `
    <section>
      <h2 class="course-title">${title}</h2>
      <p class="course-code">${code}</p>
      <div class="attendance-card">
        <div class="attendance-head">
          <span>Attendance summary</span>
          <span class="muted" style="font-weight:400">${classes} / ${total} classes</span>
        </div>
        <div class="attendance-score ${good ? 'good' : ''}">${score}%</div>
        <div class="progress">
          <span class="${good ? 'good' : ''}" style="width:${score}%"></span>
        </div>
        <div class="status-note ${good ? 'good' : ''}">${good ? 'Above' : 'Below'} 75% minimum</div>
        <div class="attendance-footer">
          <span>Attendance target: 75%</span>
          <span>${total - classes} classes missed</span>
        </div>
      </div>
    </section>
  `;
}

const views = {
  home: () => `
    ${heading('Dashboard', 'Your academic overview at a glance')}
    <div class="hello">Hi, ${currentStudent}</div>
    <div class="subtitle">M.Tech (Integrated) Software Engineering</div>
    <div class="dashboard-grid">
      <div>
        <div class="tip">
          <div class="eyebrow">Study Tip</div>
          <div class="muted">ISWE212L · Next priority</div>
          <div class="tip-title">Submit Problem Set 03</div>
          <div class="muted">72% attendance · Due tomorrow, 5 PM</div>
          <button class="link" data-go="academics">View recovery action →</button>
        </div>
        <div class="stat-grid">
          <div class="card">
            <div class="stat-label">Attendance · CS204</div>
            <div class="stat-number">72%</div>
            <div class="stat-foot">Target 75%</div>
            <button class="link" data-go="academics">View details →</button>
          </div>
          <div class="card">
            <div class="stat-label">Next assignment</div>
            <div class="stat-strong">Problem Set 03</div>
            <div class="stat-foot">Tomorrow · 5 PM</div>
            <button class="link" data-go="upload">Upload →</button>
          </div>
        </div>
        <div class="section-heading">
          <h2>Today's timetable</h2>
          <button class="link" data-go="academics">View all →</button>
        </div>
        <div class="panel">
          <div class="class-row">
            <div class="time">09:00</div>
            <div>
              <div class="class-name">Data Structures</div>
              <div class="class-meta">ISWE212L · Room 204</div>
            </div>
          </div>
          <div class="class-row">
            <div class="time">11:00</div>
            <div>
              <div class="class-name">Discrete Mathematics</div>
              <div class="class-meta">IMAT201L · Room 108</div>
            </div>
          </div>
        </div>
      </div>
      <div>
        <div class="card">
          <h2 class="card-title">Academic reminders</h2>
          <div style="padding-bottom:15px;border-bottom:1px solid #eee;margin-bottom:15px">
            <div class="class-name">Problem Set 03</div>
            <div class="class-meta">ISWE212L · Due tomorrow, 5 PM</div>
          </div>
          <div>
            <div class="class-name">Attendance warning</div>
            <div class="class-meta">CS204 is below the 75% target.</div>
          </div>
          <button class="link" style="margin-top:18px" data-go="alerts">View all notifications →</button>
        </div>
        <div class="card" style="margin-top:18px">
          <h2 class="card-title">Quick actions</h2>
          <button class="primary full" data-go="upload" style="margin-bottom:10px">Upload assignment</button>
          <button class="primary full" data-go="academics">Check attendance</button>
        </div>
      </div>
    </div>
  `,

  academics: () => `
    ${heading('Attendance & Academics', 'Review your course attendance and minimum requirements')}
    <div class="course-grid">
      ${attendance(72, 18, 25, false, 'Data Structures', 'ISWE212L')}
      ${attendance(76, 19, 25, true, 'Discrete Mathematics', 'IMAT201L')}
    </div>
    <div class="section-heading" style="margin-top:28px">
      <h2>Academic actions</h2>
    </div>
    <div class="panel" style="max-width:680px">
      <div class="class-name">Attendance recovery</div>
      <p class="page-description" style="line-height:1.7;margin:9px 0 15px">
        Data Structures attendance is currently below the 75% minimum. Review upcoming classes and keep track of attendance to reach the target.
      </p>
      <button class="primary" data-go="assignments">View assignments</button>
    </div>
  `,

  upload: () => `
    ${heading('Assignment Upload', 'Submit your coursework before the deadline')}
    <div class="upload-layout">
      <form class="card upload-form" id="uploadForm">
        <label class="field-label" for="assignmentSelect">Select assignment</label>
        <select class="select" id="assignmentSelect">
          <option>ISWE212L · Problem Set 03</option>
          <option>CS204 · Lab Assignment 04</option>
          <option>IMAT201L · Tutorial Sheet 05</option>
        </select>
        <div class="muted" style="margin-top:10px">Due tomorrow, 5 PM</div>
        <label class="field-label" for="assignmentFile">Assignment file</label>
        <div class="file-drop">
          <div class="upload-symbol">⇧</div>
          <input id="assignmentFile" type="file" accept=".pdf,.doc,.docx" hidden>
          <button class="file-choose" id="chooseFile" type="button">Choose file</button>
          <div class="file-hint" id="fileHint">PDF or DOCX · Up to 10 MB</div>
        </div>
        <button class="primary full upload-submit" type="submit">Submit Assignment</button>
      </form>
      <aside class="card">
        <h2 class="card-title">Submission guidelines</h2>
        <ul class="helper-list">
          <li><strong>Accepted formats</strong>PDF, DOC, or DOCX documents.</li>
          <li><strong>Maximum file size</strong>10 MB per submission.</li>
          <li><strong>Before submitting</strong>Check that the selected file is the final version of your assignment.</li>
          <li><strong>Deadline</strong>Problem Set 03 is due tomorrow at 5 PM.</li>
        </ul>
      </aside>
    </div>
  `,

  alerts: () => `
    ${heading('Academic Notifications', 'Important updates, reminders, and attendance alerts')}
    <div class="notification-list">
      <div class="section-heading">
        <h2>Today</h2>
        <span class="muted">3 new</span>
      </div>
      <div class="tip">
        <div class="eyebrow">Study Tip</div>
        <div class="muted">ISWE212L · Next priority</div>
        <div class="tip-title">Submit Problem Set 03</div>
        <div class="muted">72% attendance · Due tomorrow, 5 PM</div>
        <button class="link" data-go="academics">View recovery action →</button>
      </div>
      <div class="notification">
        ${icons.assignment}
        <div>
          <div class="notification-title">Assignment due tomorrow</div>
          <div class="muted">CS204 · Problem Set 03 · 5 PM</div>
          <div class="muted">Please submit your work before the deadline.</div>
        </div>
        <div class="notification-time">20 min ago</div>
      </div>
      <div class="notification">
        ${icons.warning}
        <div>
          <div class="notification-title">Attendance below target</div>
          <div class="muted">CS204 · 72% attendance · Target 75%</div>
          <div class="muted">You need to attend upcoming classes to improve your percentage.</div>
        </div>
        <div class="notification-time">1 hour ago</div>
      </div>
      <div class="notification">
        ${icons.calendar}
        <div>
          <div class="notification-title">Timetable updated</div>
          <div class="muted">MA201 · 11 AM · Room 108</div>
          <div class="muted">Your class schedule has been updated.</div>
        </div>
        <div class="notification-time">2 hours ago</div>
      </div>
    </div>
  `,

  assignments: () => `
    ${heading('Assignments', 'Track upcoming coursework and submissions')}
    <div class="assignment-list">
      <div class="card assignment-card">
        <div class="eyebrow">Due tomorrow</div>
        <div class="class-name">Problem Set 03</div>
        <div class="class-meta">ISWE212L · Due tomorrow, 5 PM</div>
        <p class="page-description" style="margin-top:15px;line-height:1.7">
          Submit your completed problem set as a PDF or DOCX document.
        </p>
        <button class="primary" data-go="upload">Upload assignment</button>
      </div>
      <div class="card assignment-card">
        <div class="eyebrow" style="color:#777">Due Friday</div>
        <div class="class-name">Lab Assignment 04</div>
        <div class="class-meta">CS204 · Due Friday, 11:59 PM</div>
        <p class="page-description" style="margin-top:15px;line-height:1.7">
          Upload the final report for your lab assignment.
        </p>
        <button class="primary" data-go="upload">Upload assignment</button>
      </div>
    </div>
  `
};

function render(page) {
  currentPage = page;
  document.querySelectorAll('.side-link[data-page]').forEach((b) => {
    b.classList.toggle('active', b.dataset.page === page);
  });
  content.innerHTML = views[page]();
  content.querySelectorAll('[data-go]').forEach((b) => {
    b.addEventListener('click', () => render(b.dataset.go));
  });
  if (page === 'upload') wireUpload();
  window.scrollTo({ top: 0, behavior: 'smooth' });
}

function wireUpload() {
  const chooseFileBtn = $('#chooseFile');
  const assignmentFileInput = $('#assignmentFile');
  const fileHint = $('#fileHint');
  const uploadForm = $('#uploadForm');

  if (chooseFileBtn && assignmentFileInput) {
    chooseFileBtn.addEventListener('click', () => assignmentFileInput.click());
    assignmentFileInput.addEventListener('change', (e) => {
      const f = e.target.files[0];
      if (!f) return;
      if (f.size > 10 * 1024 * 1024) {
        toast('File exceeds the 10 MB limit.');
        e.target.value = '';
        return;
      }
      if (fileHint) {
        fileHint.textContent = `${f.name} · ${(f.size / 1024 / 1024).toFixed(2)} MB`;
      }
    });
  }

  if (uploadForm) {
    uploadForm.addEventListener('submit', (e) => {
      e.preventDefault();
      const f = assignmentFileInput ? assignmentFileInput.files[0] : null;
      if (!f) {
        toast('Please choose an assignment file first.');
        return;
      }
      if (!/\.(pdf|doc|docx)$/i.test(f.name)) {
        toast('Please choose a PDF or DOCX file.');
        return;
      }
      toast('Demo only: connect a backend to submit this assignment.');
    });
  }
}

document.querySelectorAll('.side-link[data-page]').forEach((b) => {
  b.addEventListener('click', () => render(b.dataset.page));
});

const userChip = $('#userChip');
const avatarInitial = $('#avatarInitial');
const userMenuPopup = $('#userMenuPopup');
const popupUserName = $('#popupUserName');
const mobileLogoutBtn = $('#mobileLogoutBtn');
const logoutBtn = $('#logoutButton');

function handleLogout() {
  portal.hidden = true;
  loginScreen.hidden = false;
  if (userChip) {
    userChip.hidden = true;
    userChip.setAttribute('aria-expanded', 'false');
  }
  if (userMenuPopup) {
    userMenuPopup.hidden = true;
  }
  $('#password').value = '';
  window.scrollTo({ top: 0 });
}

if (userChip) {
  userChip.addEventListener('click', (e) => {
    e.stopPropagation();
    if (!userMenuPopup) return;
    const isHidden = userMenuPopup.hidden;
    userMenuPopup.hidden = !isHidden;
    userChip.setAttribute('aria-expanded', String(isHidden));
  });
}

document.addEventListener('click', (e) => {
  if (userMenuPopup && !userMenuPopup.hidden) {
    if (!e.target.closest('#userChip') && !e.target.closest('#userMenuPopup')) {
      userMenuPopup.hidden = true;
      if (userChip) userChip.setAttribute('aria-expanded', 'false');
    }
  }
});

const loginForm = $('#loginForm');
if (loginForm) {
  loginForm.addEventListener('submit', (e) => {
    e.preventDefault();
    const regNo = $('#regNo').value.trim();
    const password = $('#password').value;
    if (!regNo || !password) {
      $('#loginError').hidden = false;
      return;
    }
    currentStudent = regNo;
    $('#headerName').textContent = regNo;
    if (popupUserName) {
      popupUserName.textContent = regNo;
    }
    if (avatarInitial) {
      avatarInitial.textContent = regNo.length >= 2 ? regNo.slice(0, 2).toUpperCase() : 'AS';
    }
    if (userChip) {
      userChip.hidden = false;
    }
    loginScreen.hidden = true;
    portal.hidden = false;
    render('home');
  });
}

if (logoutBtn) {
  logoutBtn.addEventListener('click', handleLogout);
}

if (mobileLogoutBtn) {
  mobileLogoutBtn.addEventListener('click', handleLogout);
}
