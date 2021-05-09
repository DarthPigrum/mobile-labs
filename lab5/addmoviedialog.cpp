#include "addmoviedialog.h"
#include "ui_addmoviedialog.h"

AddMovieDialog::AddMovieDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::AddMovieDialog) {
  ui->setupUi(this);
  connect(this, &QDialog::accepted, [this]() {
    yield(ui->name->text(), ui->year->value(), ui->type->text());
  });
}

AddMovieDialog::~AddMovieDialog() { delete ui; }
